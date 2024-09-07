#include<iostream>
using namespace std;

bool Check(int arr[],int s,int e,int key){

    if(s  > e)    return false;

    int mid = (s+e)/2;

    if( key < arr[mid] ) return Check(arr,s,mid -1 ,key);

    else if(arr[mid] == key) return true;

    return Check(arr,mid + 1,e,key);


}

int main(){

    int arr[6] = {2,3,4,5,6,6};

    if(Check(arr,0,5,4)){

        cout << "Found" << endl;
    }
    else{

        cout << "Not Found " << endl;
    }
}