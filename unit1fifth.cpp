#include <iostream>
using namespace std;

int main()
{
    int r, c, n;

    cout << "Enter total rows and columns: ";
    cin >> r >> c;

    cout << "Enter number of non-zero elements: ";
    cin >> n;

    int sparse[20][3]; // original triplet
    int fastT[20][3];  // transposed triplet

    cout << "Enter triplet representation (row col value):\n";
    for (int i = 0; i < n; i++)
        cin >> sparse[i][0] >> sparse[i][1] >> sparse[i][2];

    // Step 1: Initialize output header
    fastT[0][0] = c;
    fastT[0][1] = r;
    fastT[0][2] = n;

    int rowTerms[20] = {0}; // how many elements in each column of original
    int startingPos[20] = {0};

    // Step 2: Count how many elements in each column of original matrix
    for (int i = 0; i < n; i++)
        rowTerms[sparse[i][1]]++;

    // Step 3: Compute starting positions
    startingPos[0] = 1; // first real entry at index 1
    for (int i = 1; i < c; i++)
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

    // Step 4: Fast transpose fill
    for (int i = 0; i < n; i++)
    {
        int col = sparse[i][1];
        int pos = startingPos[col];

        fastT[pos][0] = sparse[i][1];
        fastT[pos][1] = sparse[i][0];
        fastT[pos][2] = sparse[i][2];

        startingPos[col]++;
    }

    // Print result
    cout << "\nFast Transpose (Triplet Form):\n";
    cout << "Row Col Val\n";
    for (int i = 0; i <= n; i++)
        cout << fastT[i][0] << "   " << fastT[i][1] << "   " << fastT[i][2] << endl;

    return 0;
}
