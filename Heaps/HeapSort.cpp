/*            Total Time Complexity:

              Best-case: O(n log n)
              Average-case: O(n log n)
              Worst-case: O(n log n)

*/
/*
              Ascending -> Build Max Heap
              Descending -> Build Min Heap
*/

#include<iostream>
using namespace std;

void Heapify(int* arr, int size, int i){
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
        Heapify(arr,size,largest);
    }
}

void HeapSort(int *arr, int size){
    int index = size - 1;
                         
    for(int i=index/2; i>=0; i--){         //Step # 1 build heap(excluding Leaf)
        Heapify(arr,size,i);
    }   
                                      
    while( index > 0 ){
        swap(arr[0],arr[index]);           //Step # 2 swap first and last
        index--;
        Heapify(arr, index, 0);            //Step # 3 Build  Heap
    }
}

int main(){
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    HeapSort(arr, size);

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}
