# Tiene una serie de tiempo, donde los datos de tiempo estan almacenados en un arreglo t y los datos de amplitud en un arreglo amp.
#1) Usando los paquetes de scipy de la transformada de Fourier, haga un FILTRO de la senial que elimine las frecuencias mayores a 1000Hz en las senial original.
#2) Haga una grafica de la senial original y la senial filtarada y guardela SIN MOSTRARLA en filtro.pdf
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from scipy.fftpack import fft, fftfreq, ifft

n = 1280 # number of point in the whole interval
f = 200.0 #  frequency in Hz
dt = 1 / (f * 320 ) #320 samples per unit frequency
t = np.linspace( 0, (n-1)*dt, n)
amp = np.cos(2 * np.pi * f * t) - 0.4 * np.sin(2 * np.pi * (2*f) * t ) + np.random.random(n)

# SU FILTRO

Transformada = fft(amp)
#print(Transformada)

frecuencias = fftfreq(n,abs(Transformada))
print(frecuencias)

#absfrecuencias = np.real(frecuencias)
#print(absfrecuencias)

def filtro(frecuencias):
    a=np.size(frecuencias)
    new=[]
    for i in range(a):
        if(frecuencias[i]>1000 or frecuencias[i]<-1000 ):
            frecuencias[i]=0
            new.append(frecuencias[i])
        else:
            new.append(frecuencias[i])
            
    return new

frecuenciafiltrada = filtro(frecuencias)
#print(frecuenciafiltrada)

nn = ifft(frecuenciafiltrada)
#print(nn)

        

# SU GRAFICA

plt.figure()
plt.plot(t,amp,c="green")
plt.plot(t,abs(nn),c="red")
plt.xlabel("Tiempo")
plt.ylabel("Amplitud")
plt.savefig("filtro.pdf")



# Puede usar los siguientes paquetes:
#from scipy.fftpack import fft, fftfreq, ifft

