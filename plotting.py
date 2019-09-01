import matplotlib.pyplot as plt
import numpy as np 

exact_val = []
num_val = []
#x_val = []

with open("hei.txt","r") as infile:
    for i in infile:
        data = i.split()
        e_val,n_val = data[0].split("[]")[0],data[1].split("[]")[0]
        exact_val.append(float(e_val))
        num_val.append(float(n_val))
        #x_val.append(int(x_val))




plt.plot(exact_val,label="Exact value")
plt.plot(num_val, label="Numerical value")
plt.legend()
plt.show()

