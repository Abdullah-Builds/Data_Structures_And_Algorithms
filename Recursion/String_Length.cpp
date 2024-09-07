#include <iostream>
using namespace std;

int Find( string check,int index  = 0){

    if(check.length() == index) return index;

    return  Find(check,index+1);
}

int main(){

    cout << "Length of String : " << Find("abcde");

    
}