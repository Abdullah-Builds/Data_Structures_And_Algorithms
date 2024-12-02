#include <iostream>
using namespace std;

class HashTable {
public:
    int *arr;
    int size;

    HashTable(int s) {
        size = s;
        arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = -1;
        }
    }

    void rehash() {
        cout << "Rehashing ..." << endl;
        int newsize = size * 2;
        int *new_arr = new int[newsize];

        for (int i = 0; i < newsize; i++) {
            new_arr[i] = -1;
        }
        for (int i = 0; i < size; i++) {
            int val = arr[i];
            int index = val % newsize;

            while (new_arr[index] != -1) {
                index = (index + 1) % newsize;
            }
            new_arr[index] = val;
        }

        delete[] arr;
        arr = new_arr;
        size = newsize;
    }

    void insert(int val) {
        int index = val % size;
        int count = 0;

        while (arr[index] != -1 && count < size) {
            index = (index + 1) % size;
            count++;
        }

        if (count < size) {
            arr[index] = val;
        } else {
            rehash();
            insert(val);
        }
    }

    void deleteValue(int val) {
        int index = val % size;
        int count = 0;

        while (arr[index] != -1 && count < size) {
            if (arr[index] == val) {
                arr[index] = -1;
                return;
            }
            index = (index + 1) % size;
            count++;
        }
    }

    bool search(int val) {
        int index = val % size;
        int count = 0;

        while (arr[index] != -1 && count < size) {
            if (arr[index] == val) {
                return true;
            }
            index = (index + 1) % size;
            count++;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index: " << i << " " << arr[i] << endl;
        }
    }
    ~HashTable(){
        delete []arr;
    }
};

int main() {
    HashTable h1(3);
    h1.insert(1);
    h1.insert(3);
    h1.insert(3);
    h1.display();
    h1.insert(4);
    h1.display();
    h1.deleteValue(2);
    h1.display();
    cout << "Search 3: " << (h1.search(3) ? "Found" : "Not Found") << endl;
    cout << "Search 2: " << (h1.search(2) ? "Found" : "Not Found") << endl;
}
