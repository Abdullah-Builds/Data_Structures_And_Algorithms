#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *next;

    Node(int k, int val)
    {
        key = k;
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
                insert(temp->key, temp->value);
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

    int hashfunc(int key)
    {
        return key % size;
    }

    void insert(int key, int val)
    {
        if (loadFactor() > 0.75)
        {
            rehash();
        }
        int hash =hashfunc(key);
        Node *newNode = new Node(key, val);

        if (!arr[hash])
        {
            arr[hash] = newNode;
        }
        else
        {
            Node *temp = arr[hash];
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        count++;
    }

    void deleteValue(int key)
    {
        int hash =hashfunc(key);
        Node *temp = arr[hash];
        Node *prev = nullptr;

        while (temp != nullptr)
        {
            if (temp->key == key) // Compare using key
            {
                if (prev == nullptr)
                {
                    arr[hash] = temp->next;
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

    bool search(int key)
    {
        int hash =hashfunc(key);

        Node *temp = arr[hash];
        while (temp != nullptr)
        {
            if (temp->key == key) // Compare using key
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
                cout << "(Key: " << temp->key << ", Value: " << temp->value << ") ";
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
    for (int i = 0; i < 5; i++)
    {
        h1.insert(i + 1, (i + 2)); // Insert values with keys
    }
    h1.display();

    cout << "Search for key 3: " << (h1.search(3) ? "Found" : "Not Found") << endl;
    cout << "Search for key 5: " << (h1.search(5) ? "Found" : "Not Found") << endl;

    h1.deleteValue(3);
    cout << "After deletion of key 3:" << endl;
    h1.display();

    return 0;
}
