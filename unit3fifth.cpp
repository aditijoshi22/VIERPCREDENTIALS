#include <iostream>
using namespace std;

struct Node
{
    string caller;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

// Add incoming call (enqueue)
void newCall(string name)
{
    Node *t = new Node;
    t->caller = name;
    t->next = NULL;

    if (rear == NULL)
    { // first call
        front = rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }
    cout << "Call received from: " << name << endl;
}

// Agent handles a call (dequeue)
void answerCall()
{
    if (front == NULL)
    {
        cout << "No calls. System waiting...\n";
        return;
    }

    cout << "Agent answering call of: " << front->caller << endl;

    Node *temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL; // queue became empty
    delete temp;
}

int main()
{
    // Incoming calls
    newCall("Customer A");
    newCall("Customer B");
    newCall("Customer C");

    // Agents answering
    answerCall(); // Customer A
    answerCall(); // Customer B
    answerCall(); // Customer C

    // No calls left
    answerCall(); // System waiting

    return 0;
}
