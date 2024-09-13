#include<iostream>
using namespace std;

    int f(int x, int *py, int **ppz) {
        int y, z;
        **ppz += 1;
        z = **ppz;
        *py += 2;
        y = *py;
        x += 3;
        cout << x << y << z << endl;
        return x + y + z;
    }

    int main() {
        int c, *b, **a;
        c = 4;
        b = &c;
        a = &b;
         cout << c << *b << **a << endl;
        cout << f(c, b, a);
        cout << c << *b << **a << endl;
        return 0;
    }