#include <iostream>
#include <fstream>
using namespace std;

int main(){
    
    float l = 1;
    float c =300;
    float A=0.01;
    float delta_x = 0.005;
    float delta_t = 0.001;
    int nx = ((l)/delta_x)+1;
    float ti = 0;
    float tf = 0.1;
    float upas[nx];
    float upre[nx];
    float upos[nx];
    
    int i;
    
    for(i = 1;i <= nx; i++){
        if(i<nx/2){
           upre[i]=(A/(l/2))*i*delta_x;
        }
        else{
            upre[i]=(-(A/(l/2))*i*delta_x)+(2*A);
        }
         cout<<upre[i]<<endl;
    }
    
    while(ti<tf){
        for(i = 1;i <= nx; i++){
        if(ti=0){
           upos[i]=((c*c)*(delta_t*delta_t)/(2*(delta_x*delta_x)))*(upre[i+1]+upre[i-1]-2*upre[i])+(2*upre[i]);
        }
        else{
            upos[i]=((c*c)*(delta_t*delta_t)/((delta_x*delta_x)))*(upre[i+1]+upre[i-1]-2*upre[i])-upas[i]+(2*upre[i]);
        }
    }
        ti += delta_t;
        
    }
    
    
    for(i=0;i<nx;i++){
    upas[i] = upre[i]
    upre[i] = upos[i];
      }
    
   
    
      return 0;
}
