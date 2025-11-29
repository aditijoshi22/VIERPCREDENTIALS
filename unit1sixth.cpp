#include <iostream>
using namespace std;

void print(int a[20][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

bool verify(int a[20][20], int n)
{
    int sum = 0, temp;

    // Row 0 sum
    for (int j = 0; j < n; j++)
        sum += a[0][j];

    // Check rows
    for (int i = 1; i < n; i++)
    {
        temp = 0;
        for (int j = 0; j < n; j++)
            temp += a[i][j];
        if (temp != sum)
            return false;
    }

    // Check columns
    for (int j = 0; j < n; j++)
    {
        temp = 0;
        for (int i = 0; i < n; i++)
            temp += a[i][j];
        if (temp != sum)
            return false;
    }

    // Diagonal 1
    temp = 0;
    for (int i = 0; i < n; i++)
        temp += a[i][i];
    if (temp != sum)
        return false;

    // Diagonal 2
    temp = 0;
    for (int i = 0; i < n; i++)
        temp += a[i][n - 1 - i];
    if (temp != sum)
        return false;

    return true;
}

void oddMagic(int a[20][20], int n)
{
    int i = 0, j = n / 2;

    for (int k = 1; k <= n * n; k++)
    {
        a[i][j] = k;
        int ni = (i - 1 + n) % n;
        int nj = (j + 1) % n;

        if (a[ni][nj] != 0) // cell already filled
            i = (i + 1) % n;
        else
        {
            i = ni;
            j = nj;
        }
    }
}

void doublyEvenMagic(int a[20][20], int n)
{
    int num = 1, rev = n * n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Fill normally
            a[i][j] = num++;

            // Special blocks where values must be reversed
            if ((i % 4 == j % 4) || ((i + j) % 4 == 3))
                a[i][j] = rev;

            rev--;
        }
    }
}

int main()
{
    int n;
    int a[20][20] = {0};

    cout << "Enter order of magic square: ";
    cin >> n;

    if (n % 2 == 1)
    {
        oddMagic(a, n);
    }
    else if (n % 4 == 0)
    {
        doublyEvenMagic(a, n);
    }
    else
    {
        cout << "Singly-even magic squares (like 6,10,14) are too complex.\n";
        return 0;
    }

    cout << "\nMagic Square:\n";
    print(a, n);

    if (verify(a, n))
        cout << "\nMagic Square is VALID.\n";
    else
        cout << "\nMagic Square is NOT valid.\n";

    return 0;
}
