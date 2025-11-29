#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int x)
{
    Node *t = new Node;
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

Node *insert(Node *root, int x)
{
    if (root == NULL)
        return createNode(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

Node *findMin(Node *root)
{
    while (root->left)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int x)
{
    if (!root)
        return NULL;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else
    {
        if (!root->left)
        {
            Node *t = root->right;
            delete root;
            return t;
        }
        if (!root->right)
        {
            Node *t = root->left;
            delete root;
            return t;
        }
        Node *t = findMin(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

// simple level order without extra structs
void levelOrder(Node *root)
{
    if (!root)
        return;
    Node *q[50];
    int f = 0, r = 0;
    q[r++] = root;

    while (f < r)
    {
        Node *n = q[f++];
        cout << n->data << " ";
        if (n->left)
            q[r++] = n->left;
        if (n->right)
            q[r++] = n->right;
    }
}

int main()
{
    Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Level order: ";
    levelOrder(root);

    root = deleteNode(root, 30);

    cout << "\nAfter delete 30: ";
    levelOrder(root);

    return 0;
}
