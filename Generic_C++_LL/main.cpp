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
    cout << "\n"
         << "Value at index : "
         << obj3[1];
    cout << "\n";
    link<int> obj2;
    obj2.ins_beg(1);
    obj2.ins_beg(2);
    obj2.dis();
    cout << "\n";
    ++obj2;
    obj2[1]++;
    --obj2;
    obj2.dis();
    cout << "\n";
    return 0;
}