#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
    
    float l = 1;
    float c =300;
    float A=0.01;
    float delta_x = 0.005;
    float delta_t = 0.00001;
    int nx = ((l)/delta_x)+1;
    float ti = 0;
    float tf = 0.1;
    float upas[nx];
    float upre[nx];
    float upos[nx];
    float k = ((c*c)*(delta_t*delta_t));
    
    int i;
    
    //Creación Condicion inicial
    
    for(i = 1;i <= nx-1; i++){
        if(i<(nx/2)+1){
           upas[i]=(A/(l/2))*i*delta_x;
        }
        else{
            upas[i]=(-(A/(l/2))*i*delta_x)+(2*A);
        }
         cout<<upas[i]<<endl;
    }
    
            
        
    
    //Recorrido en el tiempo 
    
    int cont = 0;
    
    while(ti<tf){
        
        //condicion inicial
        
        for(i = 1;i <= nx; i++){
            upas[nx]=A*sin((3*c*ti*M_PI)/l);
        }
        
        // Para el tiempo 0 
        
        if(ti==0) {
            for(i = 1;i<nx; i++){
              upre[i]=(k/(2*(delta_x*delta_x)))*(upas[i+1]+upas[i-1]-2*upas[i])+(upas[i]);
            }
             for(i=1;i<nx;i++){
                upas[i] = upre[i];
             }
                }
        
        // Para el resto del tiempo
        
        else {
            
            for(i = 1;i<nx; i++){
              upos[i]=(k/(delta_x*delta_x))*(upre[i+1]+upre[i-1]-2*upre[i])-upas[i]+(2*upre[i]);
              }
            
            for(i=1;i<nx;i++){
                upas[i] = upre[i];
                upre[i] = upos[i];
              }
           
        }
        
     ti += delta_t;
     cont++;
  
        if(cont==201){
            for(i=0;i<nx;i++){
                cout<<upre[i]<<endl;
            }
            cont =0;
        }
    }
    
   
      return 0;
}