#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *create(int x)
{
    return new Node{x, NULL, NULL};
}

// Insert in BST
Node *insert(Node *root, int x)
{
    if (!root)
        return create(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// Find minimum (leftmost node)
int findMin(Node *root)
{
    if (!root)
        return -1;
    while (root->left)
        root = root->left;
    return root->data;
}

// Find maximum (rightmost node)
int findMax(Node *root)
{
    if (!root)
        return -1;
    while (root->right)
        root = root->right;
    return root->data;
}

// Inorder display (optional)
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 80);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nMinimum: " << findMin(root);
    cout << "\nMaximum: " << findMax(root);

    return 0;
}
