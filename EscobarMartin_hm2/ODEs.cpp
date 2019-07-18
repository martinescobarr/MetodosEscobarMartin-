#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

void euler(double vx0, double vy0, double x0, double y0, double delta_t, string path);
void leapfrog(double vx0, double vy0, double x0, double y0, double delta_t, string path);
void rk(double vx0, double vy0, double x0, double y0, double delta_t, string path);
double funx(double posx, double posy);
double funy(double posx, double posy);

int main(){
    
    double vx0 = -6.35 ;
    double vy0 = 0.606 ;
    double x0 = 0.1163 ;
    double y0 = 0.9772 ;
    double dt1 = 0.002;
    double dt2 = 0.02;
    double dt3 = 0.2;
    
    
    
    
    funx(x0, y0);
    funy(x0, y0);
        
    euler(vx0, vy0, x0, y0, dt1, "eulerdt1.txt");
    leapfrog(vx0, vy0, x0, y0, dt1, "leapfrogdt1.txt");
    rk(vx0, vy0, x0, y0, dt1, "rkdt1.txt");
    
    euler(vx0, vy0, x0, y0, dt2, "eulerdt2.txt");
    leapfrog(vx0, vy0, x0, y0, dt2, "leapfrogdt2.txt");
    rk(vx0, vy0, x0, y0, dt2, "rkdt2.txt");
    
    euler(vx0, vy0, x0, y0, dt3, "eulerdt3.txt");
    leapfrog(vx0, vy0, x0, y0, dt3, "leapfrogdt3.txt");
    rk(vx0, vy0, x0, y0, dt3, "rkdt3.txt");
    
    return 0;
    
}

double funx(double posx, double posy)
{
    double G = 39.5;
    double M = 1;
    
    return ((-G*M)/(pow(pow(posx,2) + pow(posy,2),3/2))*posx);
    
}

double funy(double posx, double posy)
{
    double G = 39.5;
    double M = 1;
    
    return ((-G*M)/(pow(pow(posx,2) + pow(posy,2),3/2))*posy);
    
}




void euler(double vx0, double vy0, double x0, double y0, double delta_t, string path)
{
    ofstream outfile;
    outfile.open(path);
    double vx = vx0;
    double vy = vy0;
    double posx = x0;
    double posy = y0;
    double t = 0;
    double G = 39.5;
    double M = 1;
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

void leapfrog(double vx0, double vy0, double x0, double y0, double delta_t, string path)
{
    ofstream outfile;
    outfile.open(path);
    double vx = vx0;
    double vy = vy0;
    double posx = x0;
    double posy = y0;
    double ax;
    double ay;
    double G = 39.5;
    double M = 1;
    double t = 0;
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

void rk(double vx0, double vy0, double x0, double y0, double delta_t, string path)
{
    ofstream outfile;
    outfile.open(path);
    double vx = vx0;
    double vy = vy0;
    double posx = x0;
    double posy = y0;
    double G = 39.5;
    double M = 1;
    double t = 0;
    double tf = 20;
    double k1vx;
    double k1vy;
    double k2vx;
    double k2vy;
    double k3vx;
    double k3vy;
    double k4vx;
    double k4vy;
    double k1ax;
    double k1ay;
    double k2ax;
    double k2ay;
    double k3ax;
    double k3ay;
    double k4ax;
    double k4ay;
        
    while(t<tf){
        
        k1ax=funx(posx, posy);
        k1ay=funy(posx, posy);
        k1vx=vx;
        k1vy=vy;
        ///
        k2ax=funx(posx+k1vx*delta_t/2,posy+k1vy*delta_t/2);
        k2ay=funy(posx+k1vx*delta_t/2,posy+k1vy*delta_t/2);
        k2vx=vx+k1ax*delta_t/2;
        k2vy=vy+k1ay*delta_t/2;
        ///
        k3ax=funx(posx+k2vx*delta_t/2,posy+k2vy*delta_t/2);
        k3ay=funy(posx+k2vx*delta_t/2,posy+k2vy*delta_t/2);
        k3vx=vx+k2ax*delta_t/2;
        k3vy=vy+k2ay*delta_t/2;
        ///
        k4ax=funx(posx+k3vx*delta_t,posy+k3vy*delta_t);
        k4ay=funy(posx+k3vx*delta_t,posy+k3vy*delta_t);
        k4vx=vx+k3ax*delta_t;
        k4vy=vy+k3ay*delta_t;
        
        vx = vx + (1./6.)*(k1ax+2*k2ax+2*k3ax+k4ax)*delta_t;
        vy = vy + (1./6.)*(k1ay+2*k2ay+2*k3ay+k4ay)*delta_t;
        posx = posx + (1./6.)*(k1vx+2*k2vx+2*k3vx+k4vx)*delta_t;
        posy = posy + (1./6.)*(k1vy+2*k2vy+2*k3vy+k4vy)*delta_t;
   
        t+=delta_t;
            
        outfile << t << " " << vx << " " << vy << " " << posx << " " << posy << endl;
        
        }
    
}
