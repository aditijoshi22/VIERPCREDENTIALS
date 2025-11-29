#include <iostream>
using namespace std;

struct Node
{
    int coeff;
    int power;
    Node *next;
};

Node *createNode(int coeff, int power)
{
    Node *newNode = new Node;
    newNode->coeff = coeff;

    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node *&head, int coeff, int power)
{
    Node *newNode = createNode(coeff, power);
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
}

void displayPolynomial(Node *head)
{
    while (head != NULL)
    {
        cout << head->coeff << "x^" << head->power;
        if (head->next != NULL)
            cout << " + ";
        head = head->next;
    }
    cout << endl;
}

Node *addPolynomials(Node *p1, Node *p2)
{
    Node *result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->power == p2->power)
        {
            insertNode(result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->power > p2->power)
        {
            insertNode(result, p1->coeff, p1->power);
            p1 = p1->next;
        }
        else
        {
            insertNode(result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        insertNode(result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        insertNode(result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;

    insertNode(poly1, 4, 3);
    insertNode(poly1, 3, 2);
    insertNode(poly1, 2, 0);

    insertNode(poly2, 5, 2);
    insertNode(poly2, 1, 1);
    insertNode(poly2, 3, 0);

    cout << "Polynomial 1: ";
    displayPolynomial(poly1);

    cout << "Polynomial 2: ";
    displayPolynomial(poly2);

    Node *sum = addPolynomials(poly1, poly2);
    cout << "Sum: ";
    displayPolynomial(sum);

    return 0;
}