#include <iostream>
#include <fstream>
using namespace std;

int main(){
    
    double l = 1;
    double v = 0.0004;
    int nx = 100;
    int ny = 100;
    double Tfut[nx][ny];
    double Tpre[nx][ny];
    double delta_x = 0.01;
    double delta_t = 0.25;
    double ti = 0;
    double tf = 2500;
    
    int i;
    int k;
    
     for(i = 1;i <= nx; i++){
          for(k = 1;k <= ny; k++){
              if(i>=20 && i<=40 && k>=40 && k<=60){
                  Tpre[i][k]=100;
              }
              else{
                  Tpre[i][k]=50;
              }
              //cout<<Tpre[i][k]<<endl;
            }
         }
    
    for(i = 1;i <= nx; i++){
          for(k = 1;k <= ny; k++){
              cout<<Tpre[i][k]<<" ";
             
          }
        cout<<"\n";
    }
              
         
         return 0;
     }