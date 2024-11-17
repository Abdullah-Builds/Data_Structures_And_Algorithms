//                      Time Complexity of Heapify Up: O(log n)
   
#include<iostream>
using namespace std;

void Heapify_Up(int *arr, int size, int i ){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if( left < size && arr[largest] < arr[left]){
        largest = left;
    }
    if( right < size && arr[largest] < arr[right]){
        largest = right;
    }
    if( largest != i){
        swap(arr[largest],arr[i]);
        Heapify_Up(arr,size,largest);
    }
}

void Make_Min_Heap(int* arr, int size){

    for(int i=size/2; i>=0; i--){   //---- size/2  to ignore the leaf Nodes
       Heapify_Up(arr,size,i);
    }
}

int main(){

    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    Make_Min_Heap(arr, size);

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

}