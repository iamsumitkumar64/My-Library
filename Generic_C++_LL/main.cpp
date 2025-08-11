#include "./libs_head_files/LL_Head.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "\n";
    link<string> obj1;
    obj1.ins_beg("sumit");
    obj1.ins_beg("parmeet");
    link<string> obj3;
    obj3 = obj1;
    obj3.dis();
    cout << "\n";
    return 0;
}