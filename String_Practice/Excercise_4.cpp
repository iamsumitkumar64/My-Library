#include <iostream>
#include "../String_Lib/header.h"
using namespace std;

int main()
{
    char a[100] = "", b[100] = "";
    int ans;
    cout << "\nEnter String :";
    cin >> a;
    cout << "\nEnter SubString :";
    cin >> b;
    ans = checksubstr(a, b);
    if (ans == 1)
    {
        cout << "Matched";
    }
    else
    {
        cout << "UnMathed";
    }
    cout<<"\n";
    return 0;
}