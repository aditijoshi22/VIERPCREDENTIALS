#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertEnd(Node *&head, int data)
{
    Node *newNode = createNode(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void displayList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void bubbleSort(Node *head)
{
    if (!head)
        return;

    bool swapped;
    Node *current;
    Node *last = nullptr;

    do
    {
        swapped = false;
        current = head;

        while (current->next != last)
        {
            if (current->data > current->next->data)
            {
                // Swap the data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

int main()
{
    Node *head = nullptr;
    insertEnd(head, 5);
    insertEnd(head, 1);
    insertEnd(head, 4);
    insertEnd(head, 2);
    insertEnd(head, 8);

    cout << "Original List: ";
    displayList(head);

    bubbleSort(head);

    cout << "Sorted List: ";
    displayList(head);

    return 0;
}