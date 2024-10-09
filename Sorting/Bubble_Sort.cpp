#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap( arr[i],arr[j]);
            }
        }
    }
}

int main() {
    int arr[7] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
}
