#include<iostream>
using namespace std;

class Heap{
    public:

    int *arr;
    int size;
    int index;

    Heap(int s){
        arr = new int [s];
        size = s;
        index = 0;
    }

    Heap(){
        arr = nullptr;
    }

    void Insertion(int val){
        if( index == size -1){
            cout << "Heap is Full " << endl;
            return;
        }
        arr[index] = val;
        
        int i = index;           
        while(i > 0 ){                   //From Bottom Up for less number of operations
            int parent = (i-1)/2;

            if( arr[parent] < arr[i]){     //Max Heap
                swap(arr[parent],arr[i]);
                i = parent;
            }
            else{
                break;
            }
        }
        index++;
    }

void Deletion() {                         // Removes root element
        if (index == 0) {
            cout << "Heap is Empty" << endl;
            return;
        }
        arr[0] = arr[--index];            // Replace root with last element and reduce size
        
        int i = 0;
        while (i < index) {               // From top down
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < index && arr[left] > arr[largest]) {
                largest = left;
            }
            if (right < index && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } 
            else {
                break;
            }
        }
    }
    void print(){
        for(int i=0; i< index; i++){
            cout << arr[i] << " " ;
        }
        cout << endl;
    }

};

int main(){
    Heap h(10);
    
    h.Insertion(10);
    h.Insertion(20);
    h.Insertion(30);
    h.Insertion(5);
    h.Insertion(15);
    
    cout << "Min Heap after insertions: ";
    h.print();
    
    h.Deletion();
    cout << " Min Heap after deletion: ";
    h.print();
}