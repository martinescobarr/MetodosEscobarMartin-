#include <iostream>
#include <fstream>
using namespace std;

int main(){
    
    int A = 2;
    int nx = 80;
    int v =1;
    int i;
    int j;
    int delta_x = A/nx;
    int delta_t = (delta_x/v)*(0,25);
    int upre[nx];
    int upos[nx];