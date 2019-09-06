import matplotlib.pyplot as plt
import numpy as np 

exact_val = []
num_val = []
x_val = []

import sys

with open(sys.argv[1], 'r') as infile:
    print("Reading from "+sys.argv[1])
    for i in infile:
        data = i.split()
        e_val,n_val,x_v = data[0].split("[]")[0],data[1].split("[]")[0],data[2].split("[]")[0]
        exact_val.append(float(e_val))
        num_val.append(float(n_val))
        x_val.append(float(x_v))
        



plt.title("Exact vs Numerical value: General Algo. n=1000")
plt.plot(x_val,exact_val,label="Exact value")
plt.plot(x_val,num_val, label="Numerical value")
plt.xlabel("x value")
plt.ylabel("y value")
plt.legend()
plt.show()

