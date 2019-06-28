#include<iostream>
using namespace std;

float mult(int,float);

int main(){
    
   cout<< "el producto de a por b es: "<<mult(2,3.0)<<endl;
   return 0;
}

float mult(int a, float b){
   float c = a*b;
   return c;
}