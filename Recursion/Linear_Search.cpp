#include <iostream>
using namespace std;

bool Find(int arr[],int size,int target){

    if(size < 0) return false;

    else if(arr[0] == target) return true;

    return Find(arr+1,size-1,target);
}

int main(){

    int arr [5] = {1,2,3,4,5};

    if(Find(arr,4,8)){
        cout << "Found";
    }

    else{
        cout << "Not Found";
    }
}