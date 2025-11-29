#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[50];
    cout << "Enter marks of students:\n";
    for (int i = 0; i < n; i++)
        cin >> marks[i];

    cout << "\n--- Bubble Sort Pass by Pass ---\n";

    // Bubble Sort (Descending - topper first)
    for (int i = 0; i < n - 1; i++)
    {
        cout << "Pass " << i + 1 << ": ";
        for (int j = 0; j < n - i - 1; j++)
        {
            if (marks[j] < marks[j + 1])
            {
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }

        // Print after each pass
        for (int k = 0; k < n; k++)
            cout << marks[k] << " ";
        cout << endl;
    }

    cout << "\n--- Final Roll Numbers (Topper = Roll 1) ---\n";
    for (int i = 0; i < n; i++)
        cout << "Roll No. " << i + 1 << " → Marks: " << marks[i] << endl;

    return 0;
}
