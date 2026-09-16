#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insert(Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        while (n--)
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }

        cout << endl;
    }
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

void leafNodes(Node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }

    leafNodes(root->left);
    leafNodes(root->right);
}

int main()
{
    Node *root = NULL;
    Node *newRoot = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter BST values:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nOriginal BST Level Wise:\n";
    levelOrder(root);

    cout << "\nEnter values for New BST:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        newRoot = insert(newRoot, value);
    }

    cout << "\nNew BST Level Wise:\n";
    levelOrder(newRoot);

    cout << "\nHeight of Original BST: "
         << height(root) << endl;

    cout << "Leaf Nodes: ";
    leafNodes(root);

    return 0;
}