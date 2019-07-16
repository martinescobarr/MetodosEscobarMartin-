#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void euler(double vx0, double vy0, double x0, double y0);
void leapfrog(double vx0, double vy0, double x0, double y0);
void rk(double vx0, double vy0, double x0, double y0);
double funx(double posx, double posy);
double funy(double posx, double posy);

int main(){
    
    double vx0 = -6.35 ;
    double vy0 = 0.606 ;
    double x0 = 0.1163 ;
    double y0 = 0.9772 ;
    
    funx(x0, y0);
    funy(x0, y0);
        
    euler(vx0, vy0, x0, y0);
    leapfrog(vx0, vy0, x0, y0);
    rk(vx0, vy0, x0, y0);
    
    return 0;
    
}

double funx(double posx, double posy)
{
    double G = 1;
    double M = 1;
    
    return ((-G*M)/(pow(pow(posx,2) + pow(posy,2),3/2))*posx);
    
}

double funy(double posx, double posy)
{
    double G = 1;
    double M = 1;
    
    return ((-G*M)/(pow(pow(posx,2) + pow(posy,2),3/2))*posy);
    
}




void euler(double vx0, double vy0, double x0, double y0)
{
    ofstream outfile;
    outfile.open("datoseuler.txt");
    double vx = vx0;
    double vy = vy0;
    double posx = x0;
    double posy = y0;
    double t = 0;
    double G = 1;
    double M = 1;
    double delta_t = 0.002;
    double tf = 20;
        
        
    while(t<tf){
        vx = vx+((-G*M)/(pow(pow(posx,2) + pow(posy,2),3/2))*posx)*delta_t;
        vy = vy+((-G*M)/(pow(pow(posx,2) + pow(posy,2),3/2))*posy)*delta_t;
        posx = posx+(vx*delta_t);
        posy = posy+(vy*delta_t);
   
        t+=delta_t;
            
        outfile << t << " " << vx << " " << vy << " " << posx << " " << posy << endl;
        
        }
    
}

void leapfrog(double vx0, double vy0, double x0, double y0)
{
    ofstream outfile;
    outfile.open("datosleapfrog.txt");
    double vx = vx0;
    double vy = vy0;
    double posx = x0;
    double posy = y0;
    double ax;
    double ay;
    double G = 1;
    double M = 1;
    double t = 0;
    double delta_t = 0.002;
    double tf = 20;
        
        
    while(t<tf){
        ax= funx(posx, posy);
        ay= funy(posx,posy);
        posx = posx+(vx*delta_t)+(0.5*ax*pow(delta_t,2));
        posy = posy+(vy*delta_t)+(0.5*ay*pow(delta_t,2));
        vx = vx+0.5*(ax+funx(posx,posy))*delta_t;
        vy = vy+0.5*(ay+funy(posx,posy))*delta_t;
   
        t+=delta_t;
            
        outfile << t << " " << vx << " " << vy << " " << posx << " " << posy << endl;
        
        }
    
}

void leapfrog(double vx0, double vy0, double x0, double y0)
{
    ofstream outfile;
    outfile.open("datosleapfrog.txt");
    double vx = vx0;
    double vy = vy0;
    double posx = x0;
    double posy = y0;
    double ax;
    double ay;
    double G = 1;
    double M = 1;
    double t = 0;
    double delta_t = 0.002;
    double tf = 20;
        
        
    while(t<tf){
        ax= funx(posx, posy);
        ay= funy(posx,posy);
        posx = posx+(vx*delta_t)+(0.5*ax*pow(delta_t,2));
        posy = posy+(vy*delta_t)+(0.5*ay*pow(delta_t,2));
        vx = vx+0.5*(ax+funx(posx,posy))*delta_t;
        vy = vy+0.5*(ay+funy(posx,posy))*delta_t;
        
        k1x=((-G*M)/(pow(pow(posx,2) + pow(posy,2),3/2))*posx)*delta_t;
        k1y=((-G*M)/(pow(pow(posx,2) + pow(posy,2),3/2))*posy)*delta_t;
        k2x=funx(posx+k1x*delta_t/2,posy+k1y*delta_t/2)*delta_t;
        k2y=funy(posx+k1x*delta_t/2,posy+k1y*delta_t/2)*delta_t;
        k3x=funx(posx+k2x*delta_t/2,posy+k2y*delta_t/2)*delta_t;
        k3y=funy(posx+k2x*delta_t/2,posy+k2y*delta_t/2)*delta_t;
        k4x=funx(posx+k3x*delta_t,posy+k3y*delta_t)*delta_t;
        k4y=funy(posx+k3x*delta_t,posy+k3y*delta_t)*delta_t;
        
        
   
        t+=delta_t;
            
        outfile << t << " " << vx << " " << vy << " " << posx << " " << posy << endl;
        
        }
    
}
