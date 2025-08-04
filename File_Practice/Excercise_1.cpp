#include <iostream>
#include <fstream>
#include "../String_Lib/header.h"
using namespace std;

int main()
{
    int i = 0;
    char quote[500] = "", c;
    ifstream in("quote.txt");
    if (!in.is_open())
    {
        cout << "File not opening";
        return 0;
    }
    cout << "\n";
    while (in.get(c))
    {
        quote[i] = c;
        i++;
    }
    cout << count_words(quote);
    cout << "\n";
    return 0;
}