grafica1.pdf : data1.txt graficas.py
	python graficas.py
datos.txt : onda.cpp
	c++ onda.cpp -o ondas
	./ondas > data1.txt