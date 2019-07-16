import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq, fft2, ifft2

#Filtro de Gauss

cara2=plt.imread("cara_02_grisesMF.png")
cara3=plt.imread("cara_03_grisesMF.png")

#plt.imshow(cara2)
#plt.imshow(cara3)

fftcara2 = fft2(cara2)
fftcara3 = fft2(cara3)

fftcara3abs = abs(fft2(cara3))
fftcara2abs = abs(fft2(cara2))
#plt.imshow(np.log(fftcara3abs))

#print(fftcara3.shape)

def Gauss(x,y,c):
    r = x**2 + y**2
    return np.exp(-(r)/c)