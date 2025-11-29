#include <iostream>
using namespace std;

struct Node
{
    int prn;
    string name;
    Node *next;
};

Node *create(int p, string n)
{
    return new Node{p, n, NULL};
}

// Insert President
void insertPresident(Node *&head, int p, string n)
{
    Node *t = create(p, n);
    t->next = head;
    head = t;
}

// Insert Secretary
void insertSecretary(Node *&head, int p, string n)
{
    Node *t = create(p, n);
    if (!head)
    {
        head = t;
        return;
    }
    Node *q = head;
    while (q->next)
        q = q->next;
    q->next = t;
}

// Insert after PRN
void insertAfter(Node *&head, int p, string n, int key)
{
    Node *q = head;
    while (q && q->prn != key)
        q = q->next;
    if (!q)
        return;
    Node *t = create(p, n);
    t->next = q->next;
    q->next = t;
}

// Delete by PRN
void deletePRN(Node *&head, int p)
{
    if (!head)
        return;
    if (head->prn == p)
    {
        Node *t = head;
        head = head->next;
        delete t;
        return;
    }
    Node *q = head;
    while (q->next && q->next->prn != p)
        q = q->next;
    if (q->next)
    {
        Node *t = q->next;
        q->next = t->next;
        delete t;
    }
}

// Count nodes
int count(Node *head)
{
    int c = 0;
    while (head)
    {
        c++;
        head = head->next;
    }
    return c;
}

// Display list
void display(Node *head)
{
    while (head)
    {
        cout << head->prn << " - " << head->name << endl;
        head = head->next;
    }
}

// Search
Node *search(Node *head, int p)
{
    while (head)
    {
        if (head->prn == p)
            return head;
        head = head->next;
    }
    return NULL;
}

// Reverse list
void reverse(Node *&head)
{
    Node *prev = NULL, *cur = head, *n;
    while (cur)
    {
        n = cur->next;
        cur->next = prev;
        prev = cur;
        cur = n;
    }
    head = prev;
}

// Sort by PRN
void sortList(Node *&head)
{
    for (Node *i = head; i; i = i->next)
        for (Node *j = i->next; j; j = j->next)
            if (i->prn > j->prn)
            {
                swap(i->prn, j->prn);
                swap(i->name, j->name);
            }
}

// Concatenate two lists
Node *concat(Node *a, Node *b)
{
    if (!a)
        return b;
    Node *t = a;
    while (t->next)
        t = t->next;
    t->next = b;
    return a;
}

int main()
{
    Node *A = NULL, *B = NULL;

    // Division A
    insertPresident(A, 1, "PresA");
    insertAfter(A, 3, "MemberA", 1);
    insertSecretary(A, 5, "SecA");

    // Division B
    insertPresident(B, 10, "PresB");
    insertSecretary(B, 20, "SecB");

    cout << "Division A:\n";
    display(A);
    cout << "\nCount: " << count(A) << endl;

    cout << "\nSearch PRN 3:\n";
    Node *s = search(A, 3);
    if (s)
        cout << s->name << endl;

    cout << "\nSorted A:\n";
    sortList(A);
    display(A);

    cout << "\nReversed A:\n";
    reverse(A);
    display(A);

    cout << "\nConcatenated (A+B):\n";
    Node *C = concat(A, B);
    display(C);

    return 0;
}
