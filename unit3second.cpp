#include <iostream>
using namespace std;

struct Node
{
    int price;
    Node *next;
};

Node *topNode = NULL;

void record(int price)
{ // push
    Node *temp = new Node;
    temp->price = price;
    temp->next = topNode;
    topNode = temp;
}

int removePrice()
{ // pop
    if (topNode == NULL)
        return -1;
    int x = topNode->price;
    Node *temp = topNode;
    topNode = topNode->next;
    delete temp;
    return x;
}

int latest()
{ // peek
    if (topNode == NULL)
        return -1;
    return topNode->price;
}

bool isEmpty()
{
    return topNode == NULL;
}

int main()
{

    record(100);
    record(120);
    record(115);

    cout << "Latest price: " << latest() << endl;

    cout << "Removed: " << removePrice() << endl;
    cout << "Latest now: " << latest() << endl;

    if (isEmpty())
        cout << "No prices left\n";
    else
        cout << "Prices are recorded\n";

    return 0;
}
