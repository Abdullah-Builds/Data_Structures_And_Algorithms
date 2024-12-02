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

    // Primary hash function
    int primaryHash(int key) {
        return key % size;
    }

    // Secondary hash function
    int secondaryHash(int key) {
        return 1 + (key % (size - 1)); // Step size
    }

    void insert(int val) {
        int index = primaryHash(val);
        int step = secondaryHash(val);
        int count = 0;

        while (arr[index] != -1 && count < size) {
            index = (index + step) % size; // Double hashing formula
            count++;
        }

        if (count < size) {
            arr[index] = val;
        } else {
            rehash();
            insert(val);
        }
    }

    void rehash() {
        cout << "Rehashing ..." << endl;
        int newsize = size * 2;
        int *arr2 = new int[newsize];
        for (int i = 0; i < newsize; i++) {
            arr2[i] = -1;
        }

        for (int i = 0; i < size; i++) {
            if (arr[i] != -1) { // Skip empty slots
                int val = arr[i];
                int index = val % newsize;
                int step = 1 + (val % (newsize - 1));
                int count = 0;

                while (arr2[index] != -1) {
                    index = (index + step) % newsize;
                    count++;
                }
                arr2[index] = val;
            }
        }

        delete[] arr;
        arr = arr2;
        size = newsize;
    }

    bool search(int val) {
        int index = primaryHash(val);
        int step = secondaryHash(val);
        int count = 0;

        while (count < size && arr[index] != -1) {
            if (arr[index] == val) {
                return true;
            }
            index = (index + step) % size;
            count++;
        }
        return false;
    }

    void deleted(int val) {
        int index = primaryHash(val);
        int step = secondaryHash(val);
        int count = 0;

        while (arr[index] != -1 && count < size) {
            if (arr[index] == val) {
                arr[index] = -1;
                return;
            }
            index = (index + step) % size;
            count++;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index: " << i << " " << arr[i] << endl;
        }
    }

    ~HashTable() {
        delete[] arr;
    }
};

int main() {
    HashTable h1(3);
    h1.insert(1);
    h1.insert(2);
    h1.insert(3);
    h1.display();
    h1.insert(4);
    h1.display();

    cout << "Search 3: " << (h1.search(3) ? "Found" : "Not Found") << endl;
    h1.deleted(3);
    cout << "Search 3 after deletion: " << (h1.search(3) ? "Found" : "Not Found") << endl;
    h1.display();

    return 0;
}
