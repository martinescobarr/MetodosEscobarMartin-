#include <iostream>
#include <fstream>
using namespace std;

double euler(double x, double y);

int main(){
    
    double h = 0.01;
    double xi = 0.0;
    double xs = 2.0;
    double x0 = xi;
    double y0 = 1.0;
    double x = xs;
    double y;
    
    while(x0<x){
        y = y0+(h*euler(x0,y0));
        y0=y;
        x0 = x0 + h;
        cout<<"el factorial de 7 es "<<y0<<endl;
        }
    return 0;
}

double euler(double x, double y)
{
        return -y;
}
        