#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int data)
    {
        val = data;
        next = nullptr;
        prev = nullptr;
    }
};

void InsertTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);

    if (!head)
    {
        head = temp;
        tail = temp;
        head->next = head;
        head->prev = head;
    }
    else
    {
        temp->prev = tail;
        temp->next = head;
        tail->next = temp;
        head->prev = temp;
        tail = temp;
    }
}

void InsertHead(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);

    if (!head)
    {
        head = temp;
        tail = temp;
        head->next = head;
        head->prev = head;
    }
    else
    {
        temp->next = head;
        temp->prev = tail;
        head->prev = temp;
        tail->next = temp;
        head = temp;
    }
}

void InsertPos(Node *&head, Node *&tail, int pos, int val)
{
    if (pos <= 0)
    {
        cout << "Invalid " << endl;
        return;
    }

    if (pos == 1)
    {
        InsertHead(head, tail, val);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (temp && count < pos - 1)
    {
        temp = temp->next;
        count++;
        if (temp == head) break; 
    }

    if (temp == head && count < pos - 1)
    {
        cout << "Invalid " << endl;
        return;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    if (temp == tail)
    {
        tail = newNode;
    }
}


void print(Node *head)
{
    if (!head) return;

    Node *ptr = head;
    do
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}

void printBackward(Node *tail)
{
    if (!tail) return;

    Node *ptr = tail;
    do
    {
        cout << ptr->val << " ";
        ptr = ptr->prev;
    } while (ptr != tail);
    cout << endl;
}

void DeletePos(Node *&head, Node *&tail, int pos)
{
    if (pos <= 0 || !head)
    {
        cout << "Invalid" << endl;
        return;
    }

    Node *ptr = head;
    int count = 1;

    if (pos == 1)
    {
        if (head == tail) 
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
        return;
    }

    while (ptr && count < pos)
    {
        ptr = ptr->next;
        count++;
        if (ptr == head)
        {
            cout << "Invalid" << endl;
            return;
        }
    }

    if (count != pos)
    {
        cout << "Invalid" << endl;
        return;
    }

    if (ptr == tail)
    {
        tail = ptr->prev;
        tail->next = head;
        head->prev = tail;
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }

    delete ptr;
}

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;

    InsertTail(head, tail, 10);
    InsertHead(head, tail, 20);
    InsertPos(head, tail, 1, 15);

    cout << "Forward print : ";
    print(head);

    cout << "Backward print : ";
    printBackward(tail);

    DeletePos(head, tail, 1);
    cout << "After deletion : ";
    print(head);
}
