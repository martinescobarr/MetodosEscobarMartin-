XY_met_dt.pdf FFtImGauss.pdf ImProcesoGauss.pdf ImHybridGauss.pdf FFtIm.pdf ImProceso.pdf ImHybrid.pdf  : Plots_hw2.py eulerdt1.txt eulerdt2.txt eulerdt3.txt leapfrogdt1.txt leapfrogdt2.txt leapfrogdt3.txt rkdt1.txt rkdt2.txt rkdt3.txt
	python Plots_hw2.py 
	python Fourier.py
eulerdt1.txt eulerdt2.txt eulerdt3.txt leapfrogdt1.txt leapfrogdt2.txt leapfrogdt3.txt rkdt1.txt rkdt2.txt rkdt3.txt : a.out
	./a.out
a.out : ODEs.cpp
	g++ ODEs.cpp

  



