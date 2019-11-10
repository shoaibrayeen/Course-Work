import numpy as np
import mnist
from matplotlib import pyplot as plt

class BPA:
    def __init__(self, num_nodes_in_layers, num_epochs, learning_rate):
        self.num_nodes_in_layers = num_nodes_in_layers
        self.num_epochs = num_epochs
        self.learning_rate = learning_rate

        # build the network
        #         w1/b1    w2/b2   
        #784(inputs) ---> 20 ---> 10(output)
        #         x     z1  a1  z2  a2=y
        self.weight1 = np.random.normal(0, 1, [self.num_nodes_in_layers[0], self.num_nodes_in_layers[1]])
        self.bias1 = np.zeros((1, self.num_nodes_in_layers[1]))
        self.weight2 = np.random.normal(0, 1, [self.num_nodes_in_layers[1], self.num_nodes_in_layers[2]])
        self.bias2 = np.zeros((1, self.num_nodes_in_layers[2]))
    '''
    def plot(self, x, y, epoch ):
        plt.scatter( x, y, label = 'Error Rate',color = 'r')
        plt.xlabel('Error')
        plt.ylabel('Iteration')
        plt.title('Epoch\t:\t' + str(epoch) + 'Rate')
        plt.legend()
        plt.show()
    '''    
        
    #using Relu
    def relu(self, inputs):
        return np.maximum(inputs, 0)
    
    def softmax(self, inputs):
        exp = np.exp(inputs)
        return exp/np.sum(exp, axis = 1, keepdims = True)

    def train(self, inputs, labels):
        for epoch in range(self.num_epochs): # training begin
            i = 0
            #List = []
            #iterationList = []
            while i < len(inputs):

                # batch input
                inputs_batch = inputs[i:i + 1]
                labels_batch = labels[i:i + 1]
                
                # forward pass
                z1 = np.dot(inputs_batch, self.weight1) + self.bias1
                a1 = self.relu(z1)
                z2 = np.dot(a1, self.weight2) + self.bias2
                y = self.softmax(z2)
                
            
                # backward pass
                delta_y = (y - labels_batch) / y.shape[0]
                delta_hidden_layer = np.dot(delta_y, self.weight2.T) 
                delta_hidden_layer[a1 <= 0] = 0 # derivatives of relu
                '''
                #Appending Error and Iteration Number
                List.append(y)
                iterationList.append(i + 1)
                '''
                # backpropagation
                weight2_gradient = np.dot(a1.T, delta_y) # forward * backward
                bias2_gradient = np.sum(delta_y, axis = 0, keepdims = True)
            
                weight1_gradient = np.dot(inputs_batch.T, delta_hidden_layer)
                bias1_gradient = np.sum(delta_hidden_layer, axis = 0, keepdims = True)

                weight2_gradient += 0.01 * self.weight2
                weight1_gradient += 0.01 * self.weight1

                # stochastic gradient descent
                self.weight1 -= self.learning_rate * weight1_gradient #update weight and bias
                self.bias1 -= self.learning_rate * bias1_gradient
                self.weight2 -= self.learning_rate * weight2_gradient
                self.bias2 -= self.learning_rate * bias2_gradient
                #print('Epoch\t:\t', epoch , '/' , self.num_epochs , '\tIterations\t:\t', i)
                i += 1
            #self.plot(List, iterationList, epoch)
            print('Epoch\t:\t', epoch , '/' , self.num_epochs , '\tIterations\t:\t', i)
            
    def test(self, inputs, labels):
        input_layer = np.dot(inputs, self.weight1)
        hidden_layer = self.relu(input_layer + self.bias1)
        scores = np.dot(hidden_layer, self.weight2) + self.bias2
        probs = self.softmax(scores)
        acc = float(np.sum(np.argmax(probs, 1) == labels)) / float(len(labels))
        print('\nTest accuracy\t:\t', acc*100)






# load data
num_classes = 10
train_images = mnist.train_images() #[60000, 28, 28]
train_labels = mnist.train_labels()
test_images = mnist.test_images()
test_labels = mnist.test_labels()

print("Training!")

# data processing
X_train = train_images.reshape(train_images.shape[0], train_images.shape[1]*train_images.shape[2]).astype('float32') #flatten 28x28 to 784x1 vectors, [60000, 784]
x_train = X_train / 255 #normalization
y_train = np.eye(num_classes)[train_labels] #convert label to one-hot

X_test = test_images.reshape(test_images.shape[0], test_images.shape[1]*test_images.shape[2]).astype('float32') #flatten 28x28 to 784x1 vectors, [60000, 784]
x_test = X_test / 255 #normalization
y_test = test_labels

obj = BPA(
                 num_nodes_in_layers = [784, 20, num_classes], 
                 num_epochs = 20,
                 learning_rate = 0.0001
             )

obj.train(x_train, y_train)


print("Testing!")
obj.test(x_test, y_test)



