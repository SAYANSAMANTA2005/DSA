#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

// Sigmoid activation and its derivative
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x) {
    double s = sigmoid(x);
    return s * (1.0 - s);
}

// Loss function (Mean Squared Error)
double mse_loss(const vector<double>& y_true, const vector<double>& y_pred) {
    double loss = 0.0;
    for (size_t i = 0; i < y_true.size(); ++i) {
        loss += pow(y_true[i] - y_pred[i], 2);
    }
    return loss / y_true.size();
}

// First derivative of MSE
vector<double> mse_loss_derivative(const vector<double>& y_true, const vector<double>& y_pred) {
    vector<double> derivative(y_true.size());
    for (size_t i = 0; i < y_true.size(); ++i) {
        derivative[i] = -2.0 * (y_true[i] - y_pred[i]);
    }
    return derivative;
}

// Second derivative of MSE (constant)
vector<double> mse_loss_second_derivative(const vector<double>& y_pred) {
    return vector<double>(y_pred.size(), 2.0);
}

// Neural network class with sigmoid activation
class NewtonRaphsonNN {
private:
    int input_size, hidden_size, output_size;
    double learning_rate;
    vector<vector<double>> W1, W2;
    vector<double> b1, b2;
    vector<double> z1, a1;  // Store hidden layer pre-activation and activation

public:
    NewtonRaphsonNN(int input, int hidden, int output, double lr)
        : input_size(input), hidden_size(hidden), output_size(output), learning_rate(lr) {
        // Initialize weights with small random values
        random_device rd;
        mt19937 gen(rd());
        normal_distribution<double> dist(0.0, 0.1);

        W1.resize(input_size, vector<double>(hidden_size));
        W2.resize(hidden_size, vector<double>(output_size));
        for (auto& row : W1) for (auto& val : row) val = dist(gen);
        for (auto& row : W2) for (auto& val : row) val = dist(gen);

        // Initialize biases to zero
        b1.resize(hidden_size, 0.0);
        b2.resize(output_size, 0.0);
    }

    // Forward pass (stores z1 and a1)
    vector<double> forward(const vector<double>& X) {
        z1.resize(hidden_size);
        a1.resize(hidden_size);
        for (int j = 0; j < hidden_size; ++j) {
            z1[j] = b1[j];
            for (int i = 0; i < input_size; ++i) {
                z1[j] += X[i] * W1[i][j];
            }
            a1[j] = sigmoid(z1[j]);
        }

        vector<double> a2(output_size);
        for (int k = 0; k < output_size; ++k) {
            double z2_k = b2[k];
            for (int j = 0; j < hidden_size; ++j) {
                z2_k += a1[j] * W2[j][k];
            }
            a2[k] = z2_k;  // Linear output for regression
        }

        return a2;
    }

    // Backward pass with Newton-Raphson adjustment
    void backward(const vector<double>& X, const vector<double>& y_true, const vector<double>& y_pred) {
        // Output layer gradients
        vector<double> d_loss = mse_loss_derivative(y_true, y_pred);
        vector<double> d2_loss = mse_loss_second_derivative(y_pred);

        // Newton-Raphson delta for output layer
        vector<double> delta_output(output_size);
        for (int k = 0; k < output_size; ++k) {
            delta_output[k] = d_loss[k] / d2_loss[k];
        }

        // Update W2 and b2
        for (int j = 0; j < hidden_size; ++j) {
            for (int k = 0; k < output_size; ++k) {
                W2[j][k] -= learning_rate * delta_output[k] * a1[j];  // Fixed gradient: a1[j] instead of derivative
            }
        }
        for (int k = 0; k < output_size; ++k) {
            b2[k] -= learning_rate * delta_output[k];
        }

        // Hidden layer gradients
        vector<double> delta_hidden(hidden_size);
        for (int j = 0; j < hidden_size; ++j) {
            double error = 0.0;
            for (int k = 0; k < output_size; ++k) {
                error += delta_output[k] * W2[j][k];
            }
            delta_hidden[j] = error * sigmoid_derivative(z1[j]);  // Use stored z1 for derivative
        }

        // Update W1 and b1
        for (int i = 0; i < input_size; ++i) {
            for (int j = 0; j < hidden_size; ++j) {
                W1[i][j] -= learning_rate * delta_hidden[j] * X[i];
            }
        }
        for (int j = 0; j < hidden_size; ++j) {
            b1[j] -= learning_rate * delta_hidden[j];
        }
    }

    // Training loop
    void train(const vector<vector<double>>& X, const vector<vector<double>>& y, int epochs) {
        for (int epoch = 0; epoch < epochs; ++epoch) {
            double total_loss = 0.0;
            for (size_t sample = 0; sample < X.size(); ++sample) {
                vector<double> y_pred = forward(X[sample]);
                backward(X[sample], y[sample], y_pred);
                total_loss += mse_loss(y[sample], y_pred);
            }
            if (epoch % 100 == 0) {
                cout << "Epoch " << epoch << ", Loss: " << total_loss / X.size() << endl;
            }
        }
    }
};

// Example usage

int main() {
    // XOR input (2 features) and output (1 target: 0 or 1)
    vector<vector<double>> X = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    vector<vector<double>> y = {{0}, {1}, {1}, {0}};

    NewtonRaphsonNN nn(2, 4, 1, 0.1);  // Input: 2, Hidden: 4, Output: 1, LR=0.1
    nn.train(X, y, 5000);

    // Test the trained network
    cout << "\nPredictions after training:" << endl;
    for (auto& x : X) {
        vector<double> pred = nn.forward(x);
        cout << "Input: [" << x[0] << ", " << x[1] << "] -> Output: " << pred[0] << endl;
    }

    return 0;
}