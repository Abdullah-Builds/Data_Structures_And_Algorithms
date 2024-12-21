#include <iostream>
#include<cmath>
using namespace std;

class Node {
public:
    int key;
    int value;

    Node() {
        key = -1;
        value = -1;
    }

    Node(int k, int v) {
        key = k;
        value = v;
    }
};

class HashTable {
public:
    Node *arr;
    int size;

    HashTable(int s) {
        size = s;
        arr = new Node[size];
    }

    int hashfunc(int key) {
        return key % size;
    }

    void rehash() {
        cout << "Rehashing ..." << endl;
        int newsize = size*2;
        Node *new_arr = new Node[newsize];

        for (int i = 0; i < size; i++) {
            if (arr[i].key != -1) {
                int index = arr[i].key % newsize;
                while (new_arr[index].key != -1) {
                    index = (index + 1) % newsize;
                }
                new_arr[index] = arr[i];
            }
        }

        delete[] arr;
        arr = new_arr;
        size = newsize;
    }

    void insert(int k, int v) {
        int hash = hashfunc(k);
        int count = 0;

        while (arr[hash].key != -1 && count < size) {
            hash = (hash + 1) % size;
            count++;
        }

        if (count < size) {
            arr[hash] = Node(k, v);
        } else {
            rehash();
            insert(k, v);
        }
    }

    void deleteValue(int k) {
        int hash = hashfunc(k);
        int count = 0;

        while (arr[hash].key != -1 && count < size) {
            if (arr[hash].key == k) {
                arr[hash] = Node();
                return;
            }
            hash = (hash + 1) % size;
            count++;
        }
    }

    bool search(int k) {
        int index = hashfunc(k);
        int count = 0;

        while (arr[index].key != -1 && count < size) {
            if (arr[index].key == k) {
                return true;
            }
            index = (index + 1) % size;
            count++;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (arr[i].key != -1) {
                cout << "Index: " << i << " Key: " << arr[i].key << " Value: " << arr[i].value << endl;
            } else {
                cout << "Index: " << i << " Empty" << endl;
            }
        }
    }

    ~HashTable() {
        delete[] arr;
    }
};

int main() {
    HashTable h1(3);
    h1.insert(1, 100);
    h1.insert(3, 200);
    h1.insert(4, 300);
    h1.display();

    h1.insert(7, 400);
    h1.display();

    h1.deleteValue(3);
    h1.display();

    cout << "Search key 4: " << (h1.search(4) ? "Found" : "Not Found") << endl;
    cout << "Search key 3: " << (h1.search(3) ? "Found" : "Not Found") << endl;

    return 0;
}
