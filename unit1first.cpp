#include <iostream>
using namespace std;
int main()
{
    char str[100];
    char str2[100];
    char str3[100];
    char reverseStr[100];
    cout << "Enter First string: ";
    cin.getline(str, 100);
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    cout << "Length of string is: " << count << endl;
    for (int i = 0; str[i] != '\0'; i++)
    {
        str2[i] = str[i];
    }
    str2[count] = '\0';
    cout << "copied string is:" << str2 << endl;
    for (int i = 0; i < count; i++)
    {
        reverseStr[i] = str[count - i - 1];
    }
    reverseStr[count] = '\0';
    cout << "Reversed string is: " << reverseStr << endl;
    int j = 0;
    for (int i = 0; i < count; i++)
    {
        str3[j++] = str[i];
    }
    for (int i = 0; i < count; i++)
    {
        str3[j++] = reverseStr[i];
    }
    str3[j] = '\0';
    cout << "Concatenated string is: " << str3 << endl;

    return 0;
}