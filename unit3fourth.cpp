#include <iostream>
using namespace std;

struct Node
{
    string name;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;
int countP = 0;

// Add at rear
void enqueue(string name)
{
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
    countP++;
}

// Remove from front
void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue empty.\n";
        return;
    }
    cout << "Removed: " << front->name << endl;

    Node *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;

    delete temp;
    countP--;
}

// Show first passenger
void showFront()
{
    if (front == NULL)
        cout << "No passengers.\n";
    else
        cout << "Front passenger: " << front->name << endl;
}

int main()
{
    enqueue("Aditi");
    enqueue("Rohan");
    enqueue("Meera");

    showFront(); // Aditi
    dequeue();   // removes Aditi
    showFront(); // Rohan
    dequeue();   // removes Rohan
    showFront(); // Meera

    cout << "Passengers left: " << countP << endl;

    return 0;
}
