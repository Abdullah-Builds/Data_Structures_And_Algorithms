#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    
    Node(int data) {
        val = data;
        next = nullptr;
    }
};

void InsertTail(Node* &head, int data) {
    Node* temp = new Node(data);
    if (!head) {
        head = temp;
        return;
    }
    Node* ptr = head;
    while (ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void DeleteTail(Node* &head) {
    if (!head) return;
    
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* curr = head;
    Node* prev = nullptr;
    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    delete curr;
}

int Top(Node* head) {
    if (!head) return -1;

    Node* ptr = head;
    while (ptr->next) {
        ptr = ptr->next;
    }
    return ptr->val;
}

class Stack {
    Node* head;

public:
    Stack() {
        head = nullptr;
    }

    void push(int data) {
        InsertTail(head, data);
    }

    void pop() {
        DeleteTail(head);
    }

    int top() {
        return Top(head);
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    Stack s;
    
    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // Print the stack
    cout << "Stack: ";
    s.print();

    // Get the top element
    cout << "Top element: " << s.top() << endl;

    // Pop an element
    s.pop();
    cout << "After popping: ";
    s.print();

    // Check if stack is empty
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
