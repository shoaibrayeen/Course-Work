## Backpropagation is a supervised learning algorithm, for training Multi-layer Perceptrons. The Backpropagation algorithm looks for the minimum value of the error function in weight space using a technique called the delta rule or gradient descent. The weights that minimize the error function is then considered to be a solution to the learning problem.

## Why We Need Backpropagation?
While designing a Neural Network, in the beginning, we initialize weights with some random values or any variable for that fact.

Now obviously, we are not superhuman. So, it’s not necessary that whatever weight values we have selected will be correct, or it fits our model the best.

Okay, fine, we have selected some weight values in the beginning, but our model output is way different than our actual output i.e. the error value is huge.

Now, how will you reduce the error?

Basically, what we need to do, we need to somehow explain the model to change the parameters (weights), such that error becomes minimum.

Let’s put it in an another way, we need to train our model.

## Training A Neural Network - Backpropagation

Let me summarize the steps for you:

__Calculate the error__ – How far is your model output from the actual output.

__Minimum Error__ – Check whether the error is minimized or not.

__Update the parameters__ – If the error is huge then, update the parameters (weights and biases). After that again check the error. Repeat the process until the error becomes minimum.

__Model is ready to make a prediction__ – Once the error becomes minimum, you can feed some inputs to your model and it will produce the output.
