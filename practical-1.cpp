#include <iostream>
using namespace std;

#define MAX 5

class Stack
{
    int stack[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int book)
    {
        if (top == MAX - 1)
            cout << "Stack Overflow\n";
        else
        {
            top++;
            stack[top] = book;
            cout << "Book Returned\n";
        }
    }

    void pop()
    {
        if (top == -1)
            cout << "Stack Underflow\n";
        else
        {
            cout << "Arrange Book: " << stack[top] << endl;
            top--;
        }
    }

    void peek()
    {
        if (top == -1)
            cout << "Stack is Empty\n";
        else
            cout << "Top Book: " << stack[top] << endl;
    }

    void display()
    {
        if (top == -1)
            cout << "Stack is Empty\n";
        else
        {
            cout << "Books in Stack:\n";
            for (int i = top; i >= 0; i--)
                cout << stack[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice, book;

    do
    {
        cout << "\n1. Return Book";
        cout << "\n2. Arrange Book";
        cout << "\n3. Top Book";
        cout << "\n4. Display Stack";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Book ID: ";
            cin >> book;
            s.push(book);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Exit";
            break;

        default:
            cout << "Invalid Choice";
        }

    } while (choice != 5);

    return 0;
}