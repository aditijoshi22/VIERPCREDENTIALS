#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;
};

Node *create(int x)
{
    return new Node{x, NULL, NULL};
}

// Insert at beginning
void insertBeg(Node *&head, int x)
{
    Node *t = create(x);
    if (head)
    {
        t->next = head;
        head->prev = t;
    }
    head = t;
}

// Insert at end
void insertEnd(Node *&head, int x)
{
    Node *t = create(x);
    if (!head)
    {
        head = t;
        return;
    }
    Node *p = head;
    while (p->next)
        p = p->next;
    p->next = t;
    t->prev = p;
}

// Insert after given value
void insertAfter(Node *&head, int key, int x)
{
    Node *p = head;
    while (p && p->data != key)
        p = p->next;
    if (!p)
        return;
    Node *t = create(x);
    t->next = p->next;
    t->prev = p;
    if (p->next)
        p->next->prev = t;
    p->next = t;
}

// Delete first node
void deleteBeg(Node *&head)
{
    if (!head)
        return;
    Node *t = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    delete t;
}

// Delete last node
void deleteEnd(Node *&head)
{
    if (!head)
        return;
    if (!head->next)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *p = head;
    while (p->next)
        p = p->next;
    p->prev->next = NULL;
    delete p;
}

// Delete specific value
void deleteValue(Node *&head, int key)
{
    Node *p = head;
    while (p && p->data != key)
        p = p->next;
    if (!p)
        return;
    if (p->prev)
        p->prev->next = p->next;
    else
        head = p->next;
    if (p->next)
        p->next->prev = p->prev;
    delete p;
}

// Display
void display(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    insertBeg(head, 10);
    insertBeg(head, 5);
    insertEnd(head, 20);
    insertAfter(head, 10, 15);

    display(head);

    deleteBeg(head);
    deleteEnd(head);
    deleteValue(head, 10);

    display(head);
    return 0;
}
