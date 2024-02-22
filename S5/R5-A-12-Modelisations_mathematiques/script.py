import numpy as np
from math import sqrt

a1 = np.array([[1, 0, -5],
              [0, 1, 3],
              [0, 0, 1]])

a2 = np.array([[sqrt(3)/2, -1/2, 0],
              [1/2, sqrt(3)/2, 0],
               [0, 0, 1]])

a3 = np.array([[1, 0, 5],
              [0, 1, -3],
              [0, 0, 1]])

a = np.dot(a1, np.dot(a2, a3))
print(a)
