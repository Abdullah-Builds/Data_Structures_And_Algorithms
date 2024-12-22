#include <iostream>
#include <stdexcept>
using namespace std;

class PriorityQueue {
private:
    int *arr;
    int size;
    int index;

    void heapifyDown(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < index && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < index && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (arr[i] > arr[parent]) {
                swap(arr[i], arr[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

public:
    PriorityQueue(int s) {
        arr = new int[s];
        size = s;
        index = 0;
    }

    ~PriorityQueue() {
        delete[] arr;
    }

    void push(int val) {
        if (index == size) {
            throw overflow_error("Priority queue is full!");
        }
        arr[index] = val;
        heapifyUp(index);
        index++;
    }

    void pop() {
        if (index == 0) {
            throw underflow_error("Priority queue is empty!");
        }
        arr[0] = arr[--index];
        heapifyDown(0);
    }

    int top() {
        if (index == 0) {
            throw underflow_error("Priority queue is empty!");
        }
        return arr[0];
    }

    bool empty() {
        return index == 0;
    }

    void print() {
        int temp = index;
        for (int i = 0; i <= index; i++) {
            cout << arr[0] << " ";
            arr[0] = arr[--temp];
            heapifyDown(0);

        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(10);

    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(30);
    pq.push(15);

    cout << "Priority Queue after insertions: ";
    pq.print();

    cout << "Top element: " << pq.top() << endl;

    pq.pop();
    cout << "Priority Queue after removing top: ";
    pq.print();

    pq.pop();
    cout << "Priority Queue after removing top: ";
    pq.print();

    return 0;
}
