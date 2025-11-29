#include <iostream>
using namespace std;

struct Node
{
    int roll;
    string name;
    string branch;
    Node *next;
};

class HashTable
{
    Node **table;
    int size;
    int count;

    int hash(int key)
    {
        return key % size;
    }

    Node *createNode(int r, string n, string b)
    {
        Node *t = new Node;
        t->roll = r;
        t->name = n;
        t->branch = b;
        t->next = NULL;
        return t;
    }

    void rehash()
    {
        int oldSize = size;
        size *= 2;
        Node **oldTable = table;

        table = new Node *[size];
        for (int i = 0; i < size; i++)
            table[i] = NULL;

        count = 0;

        for (int i = 0; i < oldSize; i++)
        {
            Node *temp = oldTable[i];
            while (temp)
            {
                insert(temp->roll, temp->name, temp->branch);
                temp = temp->next;
            }
        }

        delete[] oldTable;
    }

public:
    HashTable(int s = 5)
    {
        size = s;
        count = 0;
        table = new Node *[size];
        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }

    void insert(int roll, string name, string branch)
    {
        if ((float)(count + 1) / size > 0.7)
            rehash();

        int idx = hash(roll);
        Node *t = createNode(roll, name, branch);

        t->next = table[idx];
        table[idx] = t;

        count++;
    }

    void search(int roll)
    {
        int idx = hash(roll);
        Node *temp = table[idx];

        while (temp)
        {
            if (temp->roll == roll)
            {
                cout << "Found: Roll=" << temp->roll
                     << ", Name=" << temp->name
                     << ", Branch=" << temp->branch << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Record not found.\n";
    }

    void display()
    {
        cout << "\n--- Hash Table ---\n";
        for (int i = 0; i < size; i++)
        {
            cout << i << ": ";
            Node *temp = table[i];
            while (temp)
            {
                cout << "[" << temp->roll << ", "
                     << temp->name << ", "
                     << temp->branch << "] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main()
{
    HashTable ht;

    // Direct insertions (no menu)
    ht.insert(101, "Aditi", "CSE");
    ht.insert(108, "Rohit", "IT");
    ht.insert(115, "Sneha", "ENTC");
    ht.insert(203, "Karan", "MECH");

    // Search examples
    ht.search(108);
    ht.search(500); // not found

    // Display full table
    ht.display();

    return 0;
}
