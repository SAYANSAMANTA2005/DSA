#include<bits/stdc++.h>
using namespace std;

// project simulating apporximate funct of XOR///
#define noofInputs 2
#define noofHiddenNodes 2
#define noOutputs 1
#define numTrainingSets 4

double init_wt(){ return ((double)rand())/((double)RAND_MAX);}
double sigmoid(double x){  return (1/(1 + exp(-x)));}
double dsigmoid(double x){  return x*(1-x);// d(sigma)/dx= sigma(x)*(sigma(x)-1)
}
void shuffle(int *array,size_t n){
    if(n>1){
        size_t i;
        for(i=0;i<n-1;i++){
            size_t j= i+rand()/(RAND_MAX /(n-i) +1);//finding random idx
            int t= array[j];// swaping array[i],array[j]
            array[j]=array[i];
            array[i]=t;

        }
    }
}
int main(){
  double lr =0.1;// learning rate
 double hiddenLayer[noofHiddenNodes];
 double outputLayer[noOutputs];// arrays 

 double hiddenLayerBias[noofHiddenNodes];
 double outputLayerBias[noOutputs];// bias array

 double hiddenWeights[noofInputs][noofHiddenNodes];
 double outputWeights[noofHiddenNodes][noOutputs];

double training_inputs[numTrainingSets][noofInputs]={{0.0f,0.0f},{1.0f,0.0f},{0.0f,1.0f},{1.0f,1.0f}};
double traning_outputs[numTrainingSets][noOutputs]={{0.0f},{1.0f},{1.0f},{0.0f}};

// generating random values
for(int i=0;i<noofInputs;i++){ // layer 
    for(int j=0;j<noofHiddenNodes;j++){// layer no
      hiddenWeights[i][j]= init_wt();
    }
}
for(int i=0;i<noofHiddenNodes;i++){ // layer 
    for(int j=0;j<noOutputs;j++){// layer no
      outputWeights[i][j]= init_wt();
    }
}

for(int i=0;i<noOutputs;i++){
    outputLayerBias[i]= init_wt();
}

int trainingSetOrder[]={0,1,2,3};
int noofepochs=10000;

for(int epoch =0;epoch<noofepochs;epoch++){
    shuffle(trainingSetOrder, numTrainingSets);

    for(int x=0;x<numTrainingSets;x++){
        int i= trainingSetOrder[x];
        // forward pass


        // compute  hidden layer activation 
        for(int j=0;j<noofHiddenNodes;j++){
            double activation = hiddenLayerBias[j]; // each layer has activation
            for(int k=0;k<noofInputs;k++){
                activation+= training_inputs[i][k] *hiddenWeights[k][j];// i -> idx of traing data ....
                // j-> order of hidden layor u ar at present
            }
            hiddenLayer[j]= sigmoid(activation);
        }

        // compute  output layer activation 
        for(int j=0;j<noOutputs;j++){
            double activation = outputLayerBias[j]; // each layer has activation
            for(int k=0;k<noofInputs;k++){
                activation+=  hiddenLayer[k] * outputWeights[k][j];// i -> idx of traing data ....
                // j-> order of hidden layor u ar at present
            }
            outputLayer[j]= sigmoid(activation);
        }
        cout<<" input: "<< training_inputs[i][0]<<" , "<<  training_inputs[i][1] <<" output :"<< outputLayer[0]
        <<" predicted output:"<<  traning_outputs[i][0]<< endl;
        // back propagation
        // compute change in output weights
        double deltaOutput[noOutputs];
        for(int j=0;j<noOutputs;j++){
            double error = (traning_outputs[i][j] - outputLayer[j]);
            deltaOutput[j] = error* dsigmoid(outputLayer[j]); // delta error *( derivative of error wrt weights)
        }
        // compute change in hidden weights
        double deltaHidden[noofHiddenNodes];
        for(int j=0;j<noofHiddenNodes;j++){
            double error =0.0f;
            for(int k=0;k<noOutputs;k++){
                error += deltaOutput[k]* outputWeights[j][k];
            }
            deltaHidden[j] = error* dsigmoid(hiddenLayer[j]);

        }
        // apply change weights of output layer
        for(int j=0;j<noOutputs;j++){
            outputLayerBias[j]+=deltaOutput[j]*lr;
            for(int k=0;k<noofHiddenNodes;k++){
                outputWeights[k][j] +=hiddenLayer[k]*deltaOutput[j]*lr;
            }
        }
        // apply change weights of hidden layer
        for(int j=0;j<noofHiddenNodes;j++){
            hiddenLayerBias[j]+=deltaHidden[j]*lr;
            for(int k=0;k<noofHiddenNodes;k++){
                hiddenWeights[k][j] += training_inputs[i][k]*deltaHidden[j]*lr;
            }
        }
    }
}
/// weights
    cout<< "final hidden weights: "<<endl;
    for(int j=0;j<noofHiddenNodes;j++){
        cout<<" [ ";
        for(int k=0;k<noofInputs;k++){
            cout<< hiddenWeights[k][j]<<" ";
        }
        cout<<" ]"<<endl;
    }

    cout<< "final output weights: "<<endl;
    for(int j=0;j<noOutputs;j++){
        cout<<" [ ";
        for(int k=0;k<noofHiddenNodes;k++){
            cout<< outputWeights[k][j]<<" ";
        }
        cout<<" ]"<<endl;
    }

    //// biases
 cout<< "final hidden biases: "<<endl;
  cout<<" [ ";
    for(int j=0;j<noofHiddenNodes;j++){
        cout<< hiddenLayerBias[j]<<" ";
    }
    cout<<" ]"<<endl;

    cout<< "final output biases: "<<endl;
     cout<<" [ ";
    for(int j=0;j<noOutputs;j++){
        cout<< outputLayerBias[j]<<" ";
    }
    cout<<" ]"<<endl;

}