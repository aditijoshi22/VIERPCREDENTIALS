#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *create(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// Simple binary tree insert (left → right)
Node *insert(Node *root, int x)
{
    if (root == NULL)
        return create(x);

    if (root->left == NULL)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// Inorder Traversal
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal
void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Count leaf nodes
int countLeaves(Node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

// Mirror image
void mirror(Node *root)
{
    if (!root)
        return;

    // Swap children
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

int main()
{
    Node *root = NULL;

    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nLeaf Nodes: " << countLeaves(root);

    mirror(root);
    cout << "\nInorder After Mirror: ";
    inorder(root);

    return 0;
}
