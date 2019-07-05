#include <iostream>
#include <fstream>
using namespace std;

double rkutta(double x, double y);

int main(){
    
    double h = 0.01;
    double xi = 0.0;
    double xs = 2.0;
    double x0 = xi;
    double y0 = 1.0;
    double x = xs;
    double y;
    double k1s;
    double k2;
    double k3;
    double k4;
    doble promk;
    
    
    while(x0<x){
        double k1 = h * rkutta(x0,y0);
        double k2 = h * rkutta(x0 + 0.5 * h, y0 + 0.5 * k1);
        double k3 = h * rkutta(x0 + 0.5 * h, y0 + 0.5 * k2);
        doueble k4 = h * rkutta(x0 + h, y0 + k3);
        
        doueble promk = (1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);
        
        y = y0+promk;
        y0=y;
        x0 = x0 + h;
        }
       
    return 0;
}

double rkutta(double x, double y)
{
        return -y;
}