#include<iostream>
using namespace std;
  double myPow(double x, int n) {
         
        if(n == 0) return 1.0;
        
         else  if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        
        return x * myPow(x,n-1);
    }
    

int main() {

    double x,y;
    cout << "Enter x and y i.e, x^y : " ;
    cin >> x >> y;

     cout << myPow(x,y) ;
}