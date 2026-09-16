#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertBeginning(int id)
    {
        Node *newNode = new Node;

        newNode->data = id;
        newNode->next = head;
        head = newNode;

        cout << "Book Inserted\n";
    }

    void insertEnd(int id)
    {
        Node *newNode = new Node;

        newNode->data = id;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }

        cout << "Book Inserted\n";
    }

    void deleteBeginning()
    {
        if (head == NULL)
        {
            cout << "List is Empty\n";
        }
        else
        {
            Node *temp = head;

            cout << "Deleted Book ID: " << temp->data << endl;

            head = head->next;

            delete temp;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is Empty\n";
        }
        else
        {
            Node *temp = head;

            cout << "Book IDs: ";

            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }

            cout << endl;
        }
    }
};

int main()
{
    LinkedList list;
    int choice, id;

    do
    {
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Delete from Beginning";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            list.insertBeginning(id);
            break;

        case 2:
            cout << "Enter Book ID: ";
            cin >> id;
            list.insertEnd(id);
            break;

        case 3:
            list.deleteBeginning();
            break;

        case 4:
            list.display();
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