grafica2.pdf : data2.txt graficas2.py
	python graficas.py
datos.txt : onda.cpp
	c++ onda2.cpp -o ondita
	./ondita > data1.txt