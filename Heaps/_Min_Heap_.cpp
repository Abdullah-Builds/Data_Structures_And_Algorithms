//                 Time Complexity of Heapify Up: O(log n)

#include<iostream>
using namespace std;


void Heapify_Down(int *arr, int size, int i ){
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if( left < size && arr[smallest] > arr[left]){
        smallest = left;
    }
    if( right < size && arr[smallest] > arr[right]){
        smallest = right;
    }
    if( smallest != i){
        swap(arr[smallest],arr[i]);
        Heapify_Down(arr,size,smallest);
    }
}

void Make_Max_Heap(int* arr, int size){

    for(int i=size/2; i>=0; i--){   //---- size/2  to ignore the leaf Nodes
       Heapify_Down(arr,size,i);
    }
}

int main(){
    
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    Make_Max_Heap(arr, size);

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

}

