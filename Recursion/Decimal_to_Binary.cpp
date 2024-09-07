#include<iostream>
using namespace std;

string Decimal_to_Binary(int num){

   if(num == 0) return "0";

   return  Decimal_to_Binary(num/2) + to_string(num % 2);
}
int main(){

    int num;
    cout << "Enter to Convert Decimal To Binary : " ;
    cin >> num;

    cout << Decimal_to_Binary(num);
}


// Recusrive Tree

//decimalToBinary(5)
  //|
  //+-- decimalToBinary(2) + "1"   // 5 / 2 = 2, 5 % 2 = 1
    //   |
      // +-- decimalToBinary(1) + "0"  // 2 / 2 = 1, 2 % 2 = 0
        //    |
          //  +-- decimalToBinary(0) + "1" // 1 / 2 = 0, 1 % 2 = 1
            //     |
              //   +-- "" (base case)
