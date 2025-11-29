#include <iostream>
using namespace std;

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int partitionArray(int a[], int low, int high, int n)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    // print after each partition (pass)
    printArray(a, n);

    return i + 1;
}

void quickSort(int a[], int low, int high, int n)
{
    if (low < high)
    {
        int pi = partitionArray(a, low, high, n);
        quickSort(a, low, pi - 1, n);
        quickSort(a, pi + 1, high, n);
    }
}

int findMin(int a[], int low, int high)
{
    if (low == high)
        return a[low];

    int mid = (low + high) / 2;
    int leftMin = findMin(a, low, mid);
    int rightMin = findMin(a, mid + 1, high);

    return (leftMin < rightMin ? leftMin : rightMin);
}

int findMax(int a[], int low, int high)
{
    if (low == high)
        return a[low];

    int mid = (low + high) / 2;
    int leftMax = findMax(a, low, mid);
    int rightMax = findMax(a, mid + 1, high);

    return (leftMax > rightMax ? leftMax : rightMax);
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[50];
    cout << "Enter marks:\n";
    for (int i = 0; i < n; i++)
        cin >> marks[i];

    cout << "\n--- Quick Sort Pass by Pass ---\n";
    quickSort(marks, 0, n - 1, n);

    cout << "\nSorted Marks (Ascending): ";
    printArray(marks, n);

    int minMarks = findMin(marks, 0, n - 1);
    int maxMarks = findMax(marks, 0, n - 1);

    cout << "\nMinimum Marks = " << minMarks << endl;
    cout << "Maximum Marks = " << maxMarks << endl;

    return 0;
}
