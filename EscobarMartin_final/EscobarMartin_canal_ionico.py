import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

canalionico = np.genfromtxt("Canal_ionico.txt")

def chi(ym,yo):
    return (ym-yo)**2

def circulo(x,y):
    return (x**2+y**2)**(0.5)

#def estmacion():

fig, ax = plt.subplots()
plt.axis('equal')
circle1 = plt.Circle((best_x, best_y), np.max(r_walk), color='r',fill=False)
ax.add_artist(circle1)
plt.savefig("lalalalalalala.png")
plt.close()

    
    
    