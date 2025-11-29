#include <iostream>
using namespace std;

struct Node
{
    string name;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void checkIn(string name)
{ // enqueue
    Node *t = new Node;
    t->name = name;
    t->next = NULL;

    if (rear == NULL)
    {
        front = rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }
}

string assignDoctor()
{ // dequeue
    if (front == NULL)
        return "No patients.";

    string pname = front->name;
    Node *temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
    return pname;
}

bool isEmpty()
{
    return front == NULL;
}

int main()
{

    checkIn("Aditi");
    checkIn("Rahul");
    checkIn("Meera");

    cout << "Assigned: " << assignDoctor() << endl;
    cout << "Assigned: " << assignDoctor() << endl;

    if (!isEmpty())
        cout << "Next patient: " << assignDoctor() << endl;
    else
        cout << "No patients left.\n";

    return 0;
}
