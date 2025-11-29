#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *create(int x)
{
    Node *t = new Node;
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

// Insert in BST
Node *insert(Node *root, int x)
{
    if (!root)
        return create(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

// Find a key
bool find(Node *root, int key)
{
    if (!root)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return find(root->left, key);
    return find(root->right, key);
}

// Find minimum for deletion
Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

// Delete node from BST
Node *deleteNode(Node *root, int key)
{
    if (!root)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        // CASE 1: No child
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // CASE 2: One child
        else if (!root->left)
        {
            Node *t = root->right;
            delete root;
            return t;
        }
        else if (!root->right)
        {
            Node *t = root->left;
            delete root;
            return t;
        }
        // CASE 3: Two children
        else
        {
            Node *t = findMin(root->right);
            root->data = t->data;
            root->right = deleteNode(root->right, t->data);
        }
    }
    return root;
}

// Display inorder
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
    int choice, x;

    while (true)
    {
        cout << "\n1.Insert  2.Delete  3.Find  4.Show  5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number: ";
            cin >> x;
            root = insert(root, x);
            break;

        case 2:
            cout << "Enter number to delete: ";
            cin >> x;
            root = deleteNode(root, x);
            break;

        case 3:
            cout << "Enter number to find: ";
            cin >> x;
            if (find(root, x))
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;

        case 4:
            cout << "BST (Inorder): ";
            inorder(root);
            cout << endl;
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}
