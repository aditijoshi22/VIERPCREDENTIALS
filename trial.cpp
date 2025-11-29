#include <iostream>
using namespace std;
struct node
{
    string name;
    node *next;
};
node *front = NULL;
node *rear = NULL;
void checkIN(string name)
{
    node *temp = new node;
    temp->name = name;
    temp->next = NULL;
    if (rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
string assigndoctor()
{
    if (front == NULL)
    {
        return "No patients";
    }
    string pname = front->name;
    node *temp = front;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    delete temp;
    return pname;
}
bool isEmpty()
{
    return front == NULL;
}
int main()
{
    checkIN("Aditi");
    checkIN("Rahul");
    checkIN("Meera");
    cout << "Assigned: " << assigndoctor() << endl;
    cout << "Assigned: " << assigndoctor() << endl;
    cout << "Assigned: " << assigndoctor() << endl;
    cout << "Assigned: " << assigndoctor() << endl;
    return 0;
}