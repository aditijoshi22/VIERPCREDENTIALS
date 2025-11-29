#include <iostream>
using namespace std;
int main()
{
    int r, c;
    cout << "Enter the number of rows " << endl;
    cin >> r;
    cout << "Enter the number of columns " << endl;
    cin >> c;
    int arr[r][c];
    cout << "Enter the elemenets of the array :" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] != 0)
            {
                count++;
            }
        }
    }
    // cout<<count<<endl;
    int brr[count][3];

    int i = 0;
    for (int k = 0; k < r; k++)
    {
        for (int l = 0; l < c; l++)
        {
            if (arr[k][l] != 0)
            {

                brr[i][0] = k;
                brr[i][1] = l;
                brr[i][2] = arr[k][l];
                i++;
            }
        }
    }

    cout << "The 2D matrix is B " << endl;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Transpose Of A :" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}