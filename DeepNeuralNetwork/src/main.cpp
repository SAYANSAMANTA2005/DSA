


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

// Neural network class with 3 hidden layers
class DeepNN {
private:
    int input_size, hidden_size, output_size;
    double learning_rate;
    
    // Weights and biases
    vector<vector<double>> W1, W2, W3, W4;
    vector<double> b1, b2, b3, b4;
    
    // Network states
    vector<double> z1, a1, z2, a2, z3, a3;

public:
    DeepNN(int input, int hidden, int output, double lr)
        : input_size(input), hidden_size(hidden), output_size(output), learning_rate(lr) {
        // He initialization for weights
        random_device rd;
        mt19937 gen(rd());
        normal_distribution<double> dist(0.0, sqrt(2.0/hidden));

        W1.resize(input_size, vector<double>(hidden_size));
        W2.resize(hidden_size, vector<double>(hidden_size));
        W3.resize(hidden_size, vector<double>(hidden_size));
        W4.resize(hidden_size, vector<double>(output_size));
        
        for (auto& row : W1) for (auto& val : row) val = dist(gen);
        for (auto& row : W2) for (auto& val : row) val = dist(gen);
        for (auto& row : W3) for (auto& val : row) val = dist(gen);
        for (auto& row : W4) for (auto& val : row) val = dist(gen);

        b1.resize(hidden_size, 0.0);
        b2.resize(hidden_size, 0.0);
        b3.resize(hidden_size, 0.0);
        b4.resize(output_size, 0.0);
    }

    // Forward propagation
    vector<double> forward(const vector<double>& X) {
        // Layer 1
        z1.resize(hidden_size);
        a1.resize(hidden_size);
        for (int j = 0; j < hidden_size; ++j) {
            z1[j] = b1[j];
            for (int i = 0; i < input_size; ++i) {
                z1[j] += X[i] * W1[i][j];
            }
            a1[j] = sigmoid(z1[j]);
        }

        // Layer 2
        z2.resize(hidden_size);
        a2.resize(hidden_size);
        for (int j = 0; j < hidden_size; ++j) {
            z2[j] = b2[j];
            for (int i = 0; i < hidden_size; ++i) {
                z2[j] += a1[i] * W2[i][j];
            }
            a2[j] = sigmoid(z2[j]);
        }

        // Layer 3
        z3.resize(hidden_size);
        a3.resize(hidden_size);
        for (int j = 0; j < hidden_size; ++j) {
            z3[j] = b3[j];
            for (int i = 0; i < hidden_size; ++i) {
                z3[j] += a2[i] * W3[i][j];
            }
            a3[j] = sigmoid(z3[j]);
        }

        // Output Layer (linear)
        vector<double> output(output_size);
        for (int k = 0; k < output_size; ++k) {
            output[k] = b4[k];
            for (int j = 0; j < hidden_size; ++j) {
                output[k] += a3[j] * W4[j][k];
            }
        }

        return output;
    }

    // Backward propagation
    void backward(const vector<double>& X, const vector<double>& y_true, const vector<double>& y_pred) {
        vector<double> d_loss = mse_loss_derivative(y_true, y_pred);

        // Output layer gradients
        vector<double> delta4(output_size);
        for (int k = 0; k < output_size; ++k) {
            delta4[k] = d_loss[k];
        }

        // Update output layer (W4, b4)
        for (int j = 0; j < hidden_size; ++j) {
            for (int k = 0; k < output_size; ++k) {
                W4[j][k] -= learning_rate * delta4[k] * a3[j];
            }
        }
        for (int k = 0; k < output_size; ++k) {
            b4[k] -= learning_rate * delta4[k];
        }

        // Hidden layer 3 gradients
        vector<double> delta3(hidden_size);
        for (int j = 0; j < hidden_size; ++j) {
            double error = 0.0;
            for (int k = 0; k < output_size; ++k) {
                error += delta4[k] * W4[j][k];
            }
            delta3[j] = error * sigmoid_derivative(z3[j]);
        }

        // Update hidden layer 3 (W3, b3)
        for (int i = 0; i < hidden_size; ++i) {
            for (int j = 0; j < hidden_size; ++j) {
                W3[i][j] -= learning_rate * delta3[j] * a2[i];
            }
        }
        for (int j = 0; j < hidden_size; ++j) {
            b3[j] -= learning_rate * delta3[j];
        }

        // Hidden layer 2 gradients
        vector<double> delta2(hidden_size);
        for (int j = 0; j < hidden_size; ++j) {
            double error = 0.0;
            for (int k = 0; k < hidden_size; ++k) {
                error += delta3[k] * W3[j][k];
            }
            delta2[j] = error * sigmoid_derivative(z2[j]);
        }

        // Update hidden layer 2 (W2, b2)
        for (int i = 0; i < hidden_size; ++i) {
            for (int j = 0; j < hidden_size; ++j) {
                W2[i][j] -= learning_rate * delta2[j] * a1[i];
            }
        }
        for (int j = 0; j < hidden_size; ++j) {
            b2[j] -= learning_rate * delta2[j];
        }

        // Hidden layer 1 gradients
        vector<double> delta1(hidden_size);
        for (int j = 0; j < hidden_size; ++j) {
            double error = 0.0;
            for (int k = 0; k < hidden_size; ++k) {
                error += delta2[k] * W2[j][k];
            }
            delta1[j] = error * sigmoid_derivative(z1[j]);
        }

        // Update input layer (W1, b1)
        for (int i = 0; i < input_size; ++i) {
            for (int j = 0; j < hidden_size; ++j) {
                W1[i][j] -= learning_rate * delta1[j] * X[i];
            }
        }
        for (int j = 0; j < hidden_size; ++j) {
            b1[j] -= learning_rate * delta1[j];
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
            if (epoch % 1000 == 0) {
                cout << "Epoch " << epoch << ", Loss: " << total_loss / X.size() << endl;
            }
        }
    }
};

int main() {
    // XOR input (2 features) and output (1 target: 0 or 1)
    vector<vector<double>> X = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    vector<vector<double>> y = {{0}, {1}, {1}, {0}};

    DeepNN nn(2, 4, 1, 0.001);  // Input: 2, Hidden: 4, Output: 1, LR=0.1
    nn.train(X, y, 200000);

    // Test the trained network
    cout << "\nPredictions after training:" << endl;
    for (auto& x : X) {
        vector<double> pred = nn.forward(x);
        cout << "Input: [" << x[0] << ", " << x[1] << "] -> Output: " << pred[0] << endl;
    }

    return 0;
}