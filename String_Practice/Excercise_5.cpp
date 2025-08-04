#include <iostream>
#include "../String_Lib/header.h"
using namespace std;

int main()
{
    char a[] = " wgr \trc    \nfcr \t\n";
    char *b = trail_spaces(a);
    cout << b;
    return 0;
}