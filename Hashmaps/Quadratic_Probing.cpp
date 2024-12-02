#include <iostream>
using namespace std;

class HashTable
{
public:
    int *arr;
    int size;

    HashTable(int s)
    {
        size = s;
        arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = -1;
        }
    }

    void insert(int val)
    {
        int index = val % size;
        int count = 1;

        while (arr[index] != -1 && count < size)
        {
            index = (index + count * count) % size;
            count++;
        }

        if (count < size)
        {
            arr[index] = val;
        }
        else
        {
            rehash();
            insert(val);
        }
    }

    void rehash()
    {
        cout << "Rehashing ..." << endl;
        int newsize = size * 2;
        int *arr2 = new int[newsize];
        for (int i = 0; i < newsize; i++)
        {
            arr2[i] = -1;
        }
        for (int i = 0; i < size; i++)
        {
            int val = arr[i];
            int index = val % newsize;
            int count = 1;
            while (arr2[index] != -1)
            {
                index = (index + count * count) % newsize;
                count++;
            }
            arr2[index] = val;
        }

        delete[] arr;
        arr = arr2;
        size = newsize;
    }

    bool search(int val)
    {
        int index = val % size;
        int count = 0;

        while (count < size && arr[index] != -1)
        {
            if (arr[index] == val)
            {
                return true;
            }
            index = (index + count * count) % size;
            count++;
        }
        return false;
    }
    void deleted(int val)
    {
        int index = val % size;
        int count = 0;

        while (arr[index] != -1 && count < size)
        {
            if (arr[index] == val)
            {
                arr[index] = -1;
                break;
            }
            index = (index + count * count) % size;
            count++;
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Index: " << i << " " << arr[i] << endl;
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
    h1.insert(1);
    h1.insert(2);
    h1.insert(3);
    h1.display();
    h1.insert(4);
    h1.display();
}