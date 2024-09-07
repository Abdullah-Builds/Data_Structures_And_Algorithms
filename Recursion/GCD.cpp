#include<iostream>
using namespace std;

int  Gcd(int a, int b){
  
  if(b == 0) return a;

   else  return Gcd( b, a %b );

}

int main(){

    int a,b;
    cout << "Enter numbers : " ;
    cin >> a >> b;
    
    cout << "GCD : " << Gcd(a,b);
    
}


/*

gcd(48, 18)
  |
  +-- gcd(18, 48 % 18) // 48 % 18 = 12
       |
       +-- gcd(18, 12)
            |
            +-- gcd(12, 18 % 12) // 18 % 12 = 6
                 |
                 +-- gcd(12, 6)
                      |
                      +-- gcd(6, 12 % 6) // 12 % 6 = 0
                           |
                           +-- gcd(6, 0) // base case
                                |
                                +-- 6
*/
