#include <iostream>
using namespace std;

struct Faculty
{
    int id;
    string name, dept;
    int next; // pointer for chaining
    bool occupied;
};

class HashTable
{
    Faculty table[10];
    int size;

    int hash(int key)
    {
        return key % size;
    }

public:
    HashTable(int s = 10)
    {
        size = s;
        for (int i = 0; i < size; i++)
        {
            table[i].occupied = false;
            table[i].next = -1;
        }
    }

    void insert(int id, string name, string dept)
    {
        int index = hash(id);

        // Case 1: No collision
        if (!table[index].occupied)
        {
            table[index] = {id, name, dept, -1, true};
            return;
        }

        // Collision handling
        // If existing element does NOT belong here → replacement
        int existingHome = hash(table[index].id);

        if (existingHome != index)
        {
            // swap
            Faculty temp = table[index];
            table[index] = {id, name, dept, -1, true};

            // now insert displaced record normally (linear probe)
            int pos = index;
            do
            {
                pos = (pos + 1) % size;
            } while (table[pos].occupied);

            table[pos] = temp;

            return;
        }

        // No replacement needed → normal chaining
        int chainStart = index;
        while (table[chainStart].next != -1)
            chainStart = table[chainStart].next;

        // find free slot
        int pos = index;
        do
        {
            pos = (pos + 1) % size;
        } while (table[pos].occupied);

        table[pos] = {id, name, dept, -1, true};
        table[chainStart].next = pos;
    }

    void search(int id)
    {
        int index = hash(id);

        if (!table[index].occupied)
        {
            cout << "Not found\n";
            return;
        }

        // check home bucket
        int curr = index;
        while (curr != -1)
        {
            if (table[curr].id == id)
            {
                cout << "Found: " << table[curr].id << ", "
                     << table[curr].name << ", "
                     << table[curr].dept << endl;
                return;
            }
            curr = table[curr].next;
        }

        cout << "Not found\n";
    }

    void display()
    {
        cout << "\nIndex\tID\tName\tDept\tNext\n";
        for (int i = 0; i < size; i++)
        {
            if (table[i].occupied)
                cout << i << "\t"
                     << table[i].id << "\t"
                     << table[i].name << "\t"
                     << table[i].dept << "\t"
                     << table[i].next << endl;
            else
                cout << i << "\t---\n";
        }
    }
};

int main()
{
    HashTable ht;

    // Sample faculty
    ht.insert(101, "Aditi", "CSE");
    ht.insert(205, "Rohan", "IT");
    ht.insert(315, "Sneha", "ENTC");
    ht.insert(120, "Karan", "MECH");
    ht.insert(222, "Meera", "CIVIL");

    cout << "\nFaculty Table:";
    ht.display();

    cout << "\nSearch Results:\n";
    ht.search(205);
    ht.search(999); // not found

    return 0;
}
