#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    int key;
    int val;

    Node() : key(-1), val(-1) {}
    Node(int k, int v) : key(k), val(v) {}
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

    int primaryHash(int key)
    {
        return key % size;
    }

    int secondaryHash(int key)
    {
        return 7 + (key % 7);
    }

    int DoubleHashFunc(int k, int i)
    {
        return (primaryHash(k) + i * secondaryHash(k)) % size;
    }

    void insert(int k, int val)
    {
        int count = 0;
        int hash = DoubleHashFunc(k, count);

        while (arr[hash].key != -1 && count < size)
        {
            count++;
            hash = DoubleHashFunc(k, count);
        }

        if (count < size)
        {
            arr[hash] = Node(k, val);
        }
        else
        {
            rehash();
            insert(k, val);
        }
    }

    void rehash()
    {
        int oldSize = size;
        int newsize = next_prime(size);
        size = newsize;
        Node *arr2 = new Node[newsize];

        for (int i = 0; i < oldSize; i++)
        {
            if (arr[i].key != -1)
            {
                int k = arr[i].key;
                int v = arr[i].val;
                int count = 0;
                int hash = DoubleHashFunc(k, count);

                while (arr2[hash].key != -1)
                {
                    count++;
                    hash = DoubleHashFunc(k, count);
                }

                arr2[hash] = Node(k, v);
            }
        }

        delete[] arr;
        arr = arr2;
    }

    bool search(int key)
    {

        int count = 0;
        int hash = DoubleHashFunc(key, count);
        while (count < size)
        {
            if (arr[hash].key == key)
            {
                return true;
            }
            if (arr[hash].key == -1)
            {
                return false;
            }
            hash = DoubleHashFunc(key, count);
            count++;
        }
        return false;
    }

    void deleted(int key)
    {

        int count = 0;
        int hash = DoubleHashFunc(key, count);
        while (count < size)
        {
            if (arr[hash].key == key)
            {
                arr[hash] = Node();
                return;
            }
            if (arr[hash].key == -1)
            {
                return;
            }
            hash = DoubleHashFunc(key, count);
            count++;
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Index: " << i << " Key: " << arr[i].key << " Value: " << arr[i].val << endl;
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
    h1.insert(1, 10);
    h1.insert(2, 20);
    h1.insert(3, 30);
    h1.display();
    h1.insert(4, 40);
    h1.display();

    cout << "Search 3: " << (h1.search(3) ? "Found" : "Not Found") << endl;
    h1.deleted(3);
    cout << "Search 3 after deletion: " << (h1.search(3) ? "Found" : "Not Found") << endl;
    h1.display();

    return 0;
}
