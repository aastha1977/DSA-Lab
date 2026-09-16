#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int rollNo;
    Node *left;
    Node *right;
};

Node *createNode(int rollNo)
{
    Node *newNode = new Node;

    newNode->rollNo = rollNo;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *insert(Node *root, int rollNo)
{
    if (root == NULL)
        return createNode(rollNo);

    if (rollNo < root->rollNo)
        root->left = insert(root->left, rollNo);
    else
        root->right = insert(root->right, rollNo);

    return root;
}

void inorder(Node *root)
{
    stack<Node *> s;

    Node *current = root;

    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->rollNo << " ";

        current = current->right;
    }
}

void preorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;

    s.push(root);

    while (!s.empty())
    {
        Node *current = s.top();
        s.pop();

        cout << current->rollNo << " ";

        if (current->right != NULL)
            s.push(current->right);

        if (current->left != NULL)
            s.push(current->left);
    }
}

int main()
{
    Node *root = NULL;

    root = insert(root, 105);
    root = insert(root, 102);
    root = insert(root, 110);
    root = insert(root, 101);
    root = insert(root, 103);
    root = insert(root, 108);
    root = insert(root, 115);

    cout << "Student Roll Numbers - Inorder: ";
    inorder(root);

    cout << "\nStudent Roll Numbers - Preorder: ";
    preorder(root);

    return 0;
}