import matplotlib
import matplotlib.pyplot as plt
import numpy as np

datostemp = np.genfromtxt("data.txt")

plt.imshow(datostemp)
