#include <iostream>
#include "../String_Lib/header.h"
using namespace std;

int main()
{
    char i[30] = "sumit";
    char j[30] = "parmeet";
    cout << size_tmy_strlen(i);
    cout << my_strcmp(i, j);
    cout << i << j;
    cout << "\n";
    cout << i << j;
    cout << "\n";
    my_strcat(i, j);
    cout << i << j;
    cout << "\n";
    my_strchr(i, 't');
    cout << i << j;
    cout << "\n";
    my_strstr(i, "it");
    cout << i << j;
    cout << "\n";
    reverse_inplace(i);
    cout << i << j;
    cout << "\n";
    is_palindrome("susus");
    my_strcpy(i, j);
    cout << i << j;
    cout << "\n";
    count_words(j);
    return 0;
}