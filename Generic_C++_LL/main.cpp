#include "./libs_head_files/LL_Head.h"
#include <iostream>
using namespace std;

int main()
{
    LL<string> obj1;
    cout << "\n";
    obj1.ins_mid("jet", 5);
    obj1.ins_beg("sumit");
    obj1.ins_beg("parmeet");
    cout << "\nSize :->" << obj1.getsize() << "\n";
    obj1.dis();
    obj1.ins_end("komal");
    obj1.ins_beg("wmkdjr");
    obj1.ins_end("komal");
    obj1.ins_beg("wmkdjr");
    obj1.ins_end("komal");
    obj1.ins_beg("wmkdjr");
    obj1.ins_beg("developer");
    cout << "\nSize :->" << obj1.getsize() << "\n";
    obj1.del_mid("developer");
    obj1.dis();
    cout << "\n";
    cout << "\n";
    LL<int> obj2;
    obj2.ins_beg(4);
    obj2.ins_beg(5);
    obj2.dis();
    cout << "Size :->" << obj1.getsize() << "\n";
    obj2.ins_beg(7);
    obj2.ins_beg(3);
    obj2.ins_beg(3);
    obj2.ins_beg(3);
    obj2.ins_beg(3);
    obj2.ins_beg(3);
    obj2.ins_beg(3);
    obj2.del_mid(7);
    obj2.ins_beg(3);
    obj2.del_mid(7);
    obj2.ins_beg(3);
    obj2.del_mid(7);
    cout << "Size :->" << obj1.getsize() << "\n";
    cout << "\n";
    return 0;
}