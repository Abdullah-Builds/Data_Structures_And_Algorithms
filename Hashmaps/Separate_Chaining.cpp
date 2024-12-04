#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    int scale;

    Node(int val)
    {
        value = val;
        next = nullptr;
    }
};

class HashTable
{
public:
    Node **arr;
    int size;
    int count; 

    HashTable(int s)
    {
        size = s;
        count = 0;
        arr = new Node *[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = nullptr;
        }
    }

    double loadFactor()
    {
        return (double)count / size;
    }

    void rehash()
    {
        int oldSize = size;
        size *= 2; 
        Node **oldArr = arr;
        arr = new Node *[size];
        count = 0;

        for (int i = 0; i < size; i++)
        {
            arr[i] = nullptr;
        }

       
        for (int i = 0; i < oldSize; i++)
        {
            Node *temp = oldArr[i];
            while (temp)
            {
                insert(temp->value); 
                temp = temp->next;
            }
        }

       
        for (int i = 0; i < oldSize; i++)
        {
            Node *temp = oldArr[i];
            while (temp != nullptr)
            {
                Node *toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] oldArr;
    }

    void insert(int val)
    {
        if (loadFactor() > 0.75)
        {
            //rehash(); 
        }

        int index = val % size;
        Node *newNode = new Node(val);

        if (!arr[index])
        {
            arr[index] = newNode;
        }
        else
        {
            Node *temp = arr[index];
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        count++;
    }

    void deleteValue(int val)
    {
        int index = val % size;
        Node *temp = arr[index];
        Node *prev = nullptr;

        while (temp != nullptr)
        {
            if (temp->value == val)
            {
                if (prev == nullptr)
                {
                    arr[index] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                count--; 
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    bool search(int val)
    {
        int index = val % size;

        Node *temp = arr[index];
        while (temp != nullptr)
        {
            if (temp->value == val)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void display()
    {
        cout << endl
             << "Printing : " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Index: " << i << ": ";
            Node *temp = arr[i];
            while (temp != nullptr)
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        cout << "Current Load Factor: " << loadFactor() << endl;
    }

    ~HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            Node *temp = arr[i];
            while (temp != nullptr)
            {
                Node *toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] arr;
    }
};

int main()
{
    HashTable h1(20);
    h1.insert(1);
    h1.insert(1);
    h1.insert(3);
    h1.display();
    h1.insert(1);
    h1.display();
    h1.insert(5);
    h1.insert(6);
    h1.display();
    h1.deleteValue(2);
    h1.display();
    cout << "Search 3: " << (h1.search(3) ? "Found" : "Not Found") << endl;
    cout << "Search 2: " << (h1.search(2) ? "Found" : "Not Found") << endl;
}
