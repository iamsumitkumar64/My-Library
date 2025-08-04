#include <iostream>
using namespace std;
#include "../String_Lib/header.h"

int main()
{
    char s[] = "Hello {{name}}, today is {{day}}";
    char key_val[] = "{day:yesterday},{name:sumit}";
    cout << replace_key_value(s, key_val);
    return 0;
}