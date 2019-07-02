#include <iostream>
#include <fstream>
using namespace std;

int producto(int arr1[], int arr2[]);
int productopunto(int arr1[], int arr2[]);

int main(){
    
   int arreglo1[5] = {1, 2, 3, 4, 5};
   int arreglo2[5] = {10, 20, 30, 40 ,50};
    
   cout<< "el producto de arg1 por arg2 es: "<<producto(arreglo1, arreglo2)<<endl;
   cout<< "el producto punto de arg1 por arg2 es: "<<productopunto(arreglo1, arreglo2)<<endl;
   return 0;
}

int producto(int arreglo1[], int arreglo2[]){
   int arg[5];
   for(int i=0; i<5; i++){
      arg[i] = arreglo1[i]*arreglo2[i];
      cout<<arg[i]<<endl;
   }
}

int productopunto(int arreglo1[], int arreglo2[])
{ 
    int product = 0; 
    for (int i = 0; i < 5; i++) 
        product = product + arreglo1[i]*arreglo2[i]; 
    return product;
} 