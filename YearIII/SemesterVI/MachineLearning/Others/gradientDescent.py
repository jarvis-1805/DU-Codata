import pandas as pd
import numpy as np
from sklearn import linear_model
import matplotlib.pyplot as plt

def gradientDescent(X,Y,learningRate = 0.1,iter=2):
    theta0 = 0
    theta1 = 0
    m = len(X)
    for i in range(iter):
        hypothesis = theta0 + theta1*X
        theta0 = theta0 -(-1/m) *learningRate*sum(Y-hypothesis)
        theta1 = theta1 - (-1/m) *learningRate*sum(X*(Y - hypothesis))
        print(theta0,theta1)

X = np.array([0,1,2,3,4])
Y = np.array([2,3,5,4,6])

X
Y
plt.scatter(X,Y)

gradientDescent(X,Y)