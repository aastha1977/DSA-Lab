#include <iostream>
using namespace std;

#define MAX 5

class Queue
{
    int queue[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int customer)
    {
        if (rear == MAX - 1)
            cout << "Queue Overflow\n";
        else
        {
            if (front == -1)
                front = 0;

            rear++;
            queue[rear] = customer;

            cout << "Customer Added\n";
        }
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
            cout << "Queue Underflow\n";
        else
        {
            cout << "Served Customer: " << queue[front] << endl;
            front++;

            if (front > rear)
            {
                front = -1;
                rear = -1;
            }
        }
    }

    void display()
    {
        if (front == -1)
            cout << "Queue is Empty\n";
        else
        {
            cout << "Customers: ";

            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";

            cout << endl;
        }
    }
};

int main()
{
    Queue q;
    int choice, customer;

    do
    {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Customer ID: ";
            cin >> customer;
            q.enqueue(customer);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exit";
            break;

        default:
            cout << "Invalid Choice";
        }

    } while (choice != 4);

    return 0;
}