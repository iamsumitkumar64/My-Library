#include <iostream>
#include "../Generic_C++_LL/libs_head_files/LL_Head.h"
#include "../String_Lib/header.h"
using namespace std;

int main()
{
    LL<string> ll;
    char url_block[100] = "http://www.google.com,https://www.amazon.in,https://www.kuk.ac.in/viewresult";
    tokenizer(url_block);
    return 0;
}