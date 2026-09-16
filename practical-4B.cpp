#include <iostream>
using namespace std;

struct Node
{
    int bookID;
    Node *left;
    Node *right;
};

Node *createNode(int id)
{
    Node *newNode = new Node;

    newNode->bookID = id;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->bookID << " ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->bookID << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->bookID << " ";
    }
}

int main()
{
    Node *root = createNode(100);

    root->left = createNode(50);
    root->right = createNode(150);

    root->left->left = createNode(25);
    root->left->right = createNode(75);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}