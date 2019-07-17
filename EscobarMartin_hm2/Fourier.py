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

x = np.linspace(-1,1,fftcara3.shape[1])
y = np.linspace(-1,1,fftcara3.shape[0])

dx, dy = np.meshgrid(x,y)   #Convierte el linspace a 2D

#print(dx,dy)

filtro = Gauss(dx, dy, 3.5)  # c controla el ancho del filtro
lowpass= 1-filtro
highpass= filtro
#plt.imshow(lowpass)

cara2filtrada=fftcara2*highpass

cara2final=ifft2(cara2filtrada)

#plt.imshow(1-np.real(cara2final),cmap="Greys")


cara3filtrada=fftcara3*lowpass

cara3final=ifft2(cara3filtrada)

#plt.imshow(1-np.real(cara3final),cmap="Greys")

caratotalfiltrada = cara2filtrada + cara3filtrada

caratotal = ifft2(caratotalfiltrada)

#plt.imshow(1-np.real(caratotal),cmap="Greys")

plt.figure(figsize=(6,20),dpi=100)
plt.subplot(5,2,1)
plt.title("Cara2")
plt.imshow(cara2, cmap="gray")
plt.subplot(5,2,2)
plt.title("Cara3")
plt.imshow(cara3, cmap="gray")

plt.subplot(5,2,3)
plt.title("Fft Cara2")
plt.imshow(np.log(fftcara2abs))
plt.subplot(5,2,4)
plt.title("Fft Cara3")
plt.imshow(np.log(fftcara3abs))


plt.subplot(5,2,5)
plt.title("Filtro pasa Altos")
plt.imshow(highpass)
plt.subplot(5,2,6)
plt.title("Filtro pasa Bajos")
plt.imshow(lowpass)

plt.subplot(5,2,7)
plt.title("Fft Cara2 Filtrada")
plt.imshow(np.log(abs(cara2filtrada)))
plt.subplot(5,2,8)
plt.title("Fft Cara3 Filtrada")
plt.imshow(np.log(abs(cara3filtrada)))

plt.subplot(5,2,9)
plt.title("Cara 2 Filtrada")
plt.imshow(abs(cara2final), cmap="gray")
plt.subplot(5,2,10)
plt.title("Cara 3 Filtrada")
plt.imshow(abs(cara3final), cmap="gray")
plt.savefig("procesoGauss.png")

#Imagen Hibrida 1

plt.figure(figsize=(3,5),dpi=100)
plt.imshow(1-np.real(caratotal),cmap="Greys")
plt.title("Imagen Hibrida Gauss")
plt.savefig("imagenhibridagauss.png")


#############################################################################
################################## Filtro Heavy
############################################################################

c = 1.7
cara2=plt.imread("cara_02_grisesMF.png")
cara3=plt.imread("cara_03_grisesMF.png")

#plt.imshow(cara2)
#plt.imshow(cara3)

fftcara2 = fft2(cara2)
fftcara3 = fft2(cara3)

#print(np.abs(fftcara3)/np.max(np.abs(fftcara3)))

fftcara3abs = abs(fft2(cara3))
fftcara2abs = abs(fft2(cara2))
#plt.imshow(np.log(fftcara3abs))

#print(fftcara3.shape)

def hv(x,y,c):
    r = x**2 + y**2
    return r<=c

x = np.linspace(-1,1,fftcara3.shape[1])
y = np.linspace(-1,1,fftcara3.shape[0])

dx, dy = np.meshgrid(x,y)   #Convierte el linspace a 2D

#print(dx,dy)

filtro = hv(dx, dy, c)  # c controla el ancho del filtro
lowpass= 1-filtro
highpass= filtro
#plt.imshow(lowpass)

cara2filtrada=fftcara2*highpass

cara2final=ifft2(cara2filtrada)

#plt.imshow(1-np.real(cara2final),cmap="Greys")


cara3filtrada=fftcara3*lowpass

cara3final=ifft2(cara3filtrada)

#plt.imshow(1-np.real(cara3final),cmap="Greys")

caratotalfiltrada = cara2filtrada + cara3filtrada

caratotal = ifft2(caratotalfiltrada)

#plt.imshow(1-np.real(caratotal),cmap="Greys")

#####################################################
##### Plot proceso ###########

plt.figure(figsize=(6,20))
plt.subplot(5,2,1)
plt.title("Cara2")
plt.imshow(cara2, cmap="gray")
plt.subplot(5,2,2)
plt.title("Cara3")
plt.imshow(cara3, cmap="gray")

plt.subplot(5,2,3)
plt.title("Fft Cara2")
plt.imshow(np.log(fftcara2abs))
plt.subplot(5,2,4)
plt.title("Fft Cara3")
plt.imshow(np.log(fftcara3abs))


plt.subplot(5,2,5)
plt.title("Filtro pasa Altos")
plt.imshow(highpass)
plt.subplot(5,2,6)
plt.title("Filtro pasa Bajos")
plt.imshow(lowpass)

plt.subplot(5,2,7)
plt.title("Fft Cara2 Filtrada")
plt.imshow(np.log(abs(cara2filtrada)))
plt.subplot(5,2,8)
plt.title("Fft Cara3 Filtrada")
plt.imshow(np.log(abs(cara3filtrada)))

plt.subplot(5,2,9)
plt.title("Cara 2 Filtrada")
plt.imshow(abs(cara2final),cmap="gray")
plt.subplot(5,2,10)
plt.title("Cara 3 Filtrada")
plt.imshow(abs(cara3final),cmap="gray")
plt.savefig("procesohv.png")

#Imagen Hibrida 2

plt.imshow(1-np.real(caratotal),cmap="Greys")
plt.title("Imagen Hibrida Hv")
plt.savefig("imagenhibridahv.png")