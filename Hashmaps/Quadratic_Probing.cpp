#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node() : key(-1), value(-1) {}
    Node(int k, int v) : key(k), value(v) {}
};

class HashTable
{
public:
    Node *arr;
    int size;

    HashTable(int s)
    {
        size = s;
        arr = new Node[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = Node();
        }
    }
    bool is_prime(int n)
    {
        if (n <= 1)
        {
            return false;
        }
        for (int i = 2; i <= sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    // Function to find the next prime after a given number
    int next_prime(int p)
    {
        int num = p + 1;
        while (!is_prime(num))
        {
            num++;
        }
        return num;
    }

    int hashFunction(int k, int count)
    {
        return (k + count * count) % size;
    }

    void insert(int val, int key)
    {
        int count = 0;
        int index = hashFunction(key, count);

        while (arr[index].key != -1 && arr[index].key != key && count < size)
        {
            count++;
            index = hashFunction(key, count);
        }

        if (count < size)
        {
            if (arr[index].key == -1)
            {
                arr[index] = Node(key, val);
            }
            else
            {
                arr[index].value = val;
            }
        }
        else
        {
            rehash();
            insert(val, key);
        }
    }

    void rehash()
    {
        cout << "Rehashing..." << endl;
        int newsize = next_prime(size);
        int oldsize = size;
        size = newsize;
        Node *arr2 = new Node[newsize];

        for (int i = 0; i < newsize; i++)
        {
            arr2[i] = Node();
        }

        for (int i = 0; i < oldsize; i++)
        {
            if (arr[i].key != -1)
            {
                int count = 0;
                int key = arr[i].key;
                int val = arr[i].value;
                int index = hashFunction(key, count);

                while (arr2[index].key != -1)
                {
                    count++;
                    index = hashFunction(key, count);
                }
                arr2[index] = Node(key, val);
            }
        }

        delete[] arr;
        arr = arr2;
    }

    bool search(int key)
    {
        int count = 0;
        int index = hashFunction(key, count);

        while (count < size && arr[index].key != -1)
        {
            if (arr[index].key == key)
            {
                return true;
            }
            count++;
            index = hashFunction(key, count);
        }
        return false;
    }

    void deleted(int key)
    {
        int count = 0;
        int index = hashFunction(key, count);

        while (arr[index].key != -1 && count < size)
        {
            if (arr[index].key == key)
            {
                arr[index] = Node();
                break;
            }
            count++;
            index = hashFunction(key, count);
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i].key != -1)
            {
                cout << "Index: " << i << " Key: " << arr[i].key << " Value: " << arr[i].value << endl;
            }
            else
            {
                cout << "Index: " << i << " Empty" << endl;
            }
        }
    }

    ~HashTable()
    {
        delete[] arr;
    }
};

int main()
{
    HashTable h1(3);
    h1.insert(1, 101);
    h1.insert(2, 102);
    h1.insert(3, 103);
    h1.display();
    h1.insert(4, 104);
    h1.display();

    cout << "Searching for key 102: " << (h1.search(102) ? "Found" : "Not Found") << endl;

    h1.deleted(102);
    cout << "After deletion:" << endl;
    h1.display();

    return 0;
}
