#include <iostream>
#include <fstream>
using namespace std;
#include "../String_Lib/header.h"

int main()
{
    int i = 0;
    char quote[500] = "", c;
    ifstream in("quote.txt");
    cout << "\n";
    while (in.get(c))
    {
        quote[i] = c;
        i++;
    }
    cout << quote;
    char word[400] = "";
    cout << "\n\nEnter Words to find occurrence :";
    cin >> word;
    cout << find_occur(quote, word);
    cout << "\n";
    return 0;
}