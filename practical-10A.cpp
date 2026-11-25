#include <iostream>
using namespace std;

#define SIZE 10

int table[SIZE];

void insert(int key)
{
    int index = key % SIZE;
    int start = index;

    while (table[index] != -1)
    {
        index = (index + 1) % SIZE;

        if (index == start)
        {
            cout << "Hash table is full!\n";
            return;
        }
    }

    table[index] = key;
    cout << "Inserted " << key
         << " at index " << index << endl;
}

void display()
{
    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " : ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }
}

int main()
{
    int n, key;

    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    cout << "Enter number of keys: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter key: ";
        cin >> key;
        insert(key);
    }

    display();

    return 0;
}