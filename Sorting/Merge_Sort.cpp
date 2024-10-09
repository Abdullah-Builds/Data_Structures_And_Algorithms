#include<iostream>
using namespace std;

void Merge( int* arr, int s, int e, int mid){

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* temp1 = new int [len1];                 // Copy half elemnts into one and half into other
    int* temp2 = new int [len2];
    int k = s;

    for(int i=0; i<len1; i++){
        temp1[i] = arr[k++];
    }
     for(int i=0; i<len2; i++){
        temp2[i] = arr[k++];
    }

    int index1 = 0;                                // Merge 2 sorted Arrays
    int index2 = 0;
    k = s;

    while( index1 < len1 && index2 < len2 ){
        if( temp1[index1] < temp2[index2]){
            arr[k++] = temp1[index1++];
        }
        else{
            arr[k++] = temp2[index2++];
        }
    }
    while( index1 < len1  ){
            arr[k++] = temp1[index1++];
    }
    while( index2 < len2  ){
            arr[k++] = temp2[index2++];
    }

}
void merge_Sort(int* arr, int s, int e){

    if( s >= e ){
        return;
    }
    
    int mid = s + (e-s)/2;
    merge_Sort( arr, mid+1, e);
    merge_Sort( arr,s,mid);

    Merge( arr, s, e, mid );                      // This function calls n-1 times
}
int main(){

    int arr[10] = {3,45,78,12,34,6,7,0,34,1};
    int n = 10;

    merge_Sort( arr, 0, n-1 );

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}