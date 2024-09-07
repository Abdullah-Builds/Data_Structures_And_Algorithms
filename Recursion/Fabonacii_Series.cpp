#include<iostream>
using namespace std;

int  Fabonacii(int num){
  
  if(num == 0 || num == 1) return num;

   else  return Fabonacii(num -1) + Fabonacii(num-2);

}

int main(){

    int num,i=0;
    cout << "Enter number : " ;
    cin >> num;

    while ( i < num){
    cout << Fabonacii(i);
     i++;
     
    }
    
}