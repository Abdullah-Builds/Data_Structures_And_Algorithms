#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class HashTable {
public:
    Node** arr;
    int size;

    HashTable(int s) {
        size = s;
        arr = new Node*[size];
         
        for (int i = 0; i < size; i++) {
            arr[i] = nullptr;
        }
    }

    void insert(int val) {
        int index = val % size;
        Node* newNode = new Node(val);

        if (!arr[index]) {
            arr[index] = newNode;
        }
         else {
            Node* temp = arr[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteValue(int val) {

        int index = val % size;
        Node* temp = arr[index];
        Node* prev = nullptr;

        while (temp != nullptr) {

            if (temp->value == val) {

                if (prev == nullptr) {
                    arr[index] = temp->next;
                } 
                else {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    bool search(int val) {
        int index = val % size;

        Node* temp = arr[index];
        while (temp != nullptr) {
            if (temp->value == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void display() {
        cout << endl << "Printing : " << endl;
        for (int i = 0; i < size; i++) {
            cout << "Index: " << i << ": ";
            Node* temp = arr[i];
            while (temp != nullptr) {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    ~HashTable() {
        for (int i = 0; i < size; i++) {
            Node* temp = arr[i];
            while (temp != nullptr) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
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
    h1.deleteValue(2);
    h1.display();
    cout << "Search 3: " << (h1.search(3) ? "Found" : "Not Found") << endl;
    cout << "Search 2: " << (h1.search(2) ? "Found" : "Not Found") << endl;
}
