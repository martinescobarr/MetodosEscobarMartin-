import matplotlib
import matplotlib.pyplot as plt
import numpy as np

datoscuerda = np.genfromtxt("data1.txt")
x = np.linspace(0,1,200)

plt.figure(figsize=(10,8))
plt.plot(x,datoscuerda[:200],c="violet", label="t1")
plt.plot(x,datoscuerda[200:400],c="red", label="t2")
plt.plot(x,datoscuerda[400:600],c="grey", label="t3")
plt.plot(x,datoscuerda[600:800],c="blue", label="t4")
plt.plot(x,datoscuerda[800:1000],c="yellow", label="t5")
plt.plot(x,datoscuerda[1000:1200],c="purple", label="t6")
plt.xlabel("Pos") 
plt.ylabel("Amplitud")
plt.legend()
plt.grid()
plt.savefig("grafica1.pdf")