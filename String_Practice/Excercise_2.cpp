#include <iostream>
#include <fstream>
#include "../String_Lib/header.h"
using namespace std;

int main()
{
    ifstream in("student.csv");
    char c, string[1000];
    int i = 0;
    while (in.get(c))
    {
        string[i] = c;
        i++;
    }
    string[i] = '\0';
    tokenizer(string);
    return 0;
}