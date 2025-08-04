// HashMap -> A type of data structure that is used to store user values in key-value pair. [  ]
// HashMap Various Complexities ->
// 1.) Read -> Best-O(1) Worst-O(n)
// 2.) Write -> Best-O(1) Worst-O(n)
// 3.) Deletion -> Best-O(1) Worst-O(n)

// #include "./non_generic_libs/header.h" //Not Generic
#include "./generic_libs/header.h" //Generic
using namespace std;

int main()
{
    int size, choice, capacity;
    cout << "\nEnter range of key like hash[size] :0-";
    cin >> size;
    cout << "\nAdvisable to use 80% or above";
    cout << "\nSize Should be Increase after % :";
    cin >> capacity;
    // Hash_map obj(size); // Not Generic
    Hash_map<int, int> obj(size); // Generic
    cout << "\n1 for Insert \n2 for Remove \n3 for Search \n4 for Display \n5 for DisplayALl \n6 for Count \n7 for Empty \n8 for Clear \n9 for Exit Program\n\n";
    do
    {
        // string value; // Not Generic
        // int key;      // Not Generic
        int value; // Generic
        int key;   // Generic
        cout << "\nEnter Your choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n\t\t-->-->Inserting<--<--\n";
            cout << "\tEnter Your Value :";
            cin >> value;
            cout << "\tEnter Your Key :";
            cin >> key;
            obj.Hashinsert(value, key, capacity);
            break;
        case 2:
            cout << "\n\t\t-->-->Removing<--<--\n";
            cout << "\tEnter Your Value :";
            cin >> value;
            cout << "\tEnter Your Key :";
            cin >> key;
            obj.Hashremove(value, key);
            break;
        case 3:
            cout << "\n\t\t-->-->Searching<--<--\n";
            cout << "\tEnter Your Value :";
            cin >> value;
            cout << "\tEnter Your Key :";
            cin >> key;
            obj.Hashsearch(value, key);
            break;
        case 4:
            cout << "\n\t\t-->-->Displaying ONE<--<--\n";
            cout << "\tEnter Your Key :";
            cin >> key;
            cout << "\n\tindex : =>{KEY :VALUE} ->nullptr\n";
            obj.Hashdisplay(key);
            break;
        case 5:
            cout << "\n\t\t-->-->Displaying ALL<--<--\n";
            cout << "\n\tindex : =>{KEY :VALUE} ->nullptr\n";
            obj.HashdisplayAll();
            break;
        case 6:
            cout << "\n\t\t-->-->Count ELements<--<--\n";
            cout << "Total Elements :" << obj.Hashcount();
            break;
        case 7:
            cout << "\n\t\t-->-->Empty Check<--<--\n";
            cout << (obj.Hashempty() ? "Hash is Empty" : "Hash is not Empty");
            break;
        case 8:
            obj.Hashclear();
            break;
        case 9:
            cout << "\n\n\t\t-->-->Successfully Exited<--<--\n";
            break;
        default:
            cout << "\n\t\t-->-->Wrong Choice<--<--\n";
            break;
        }
    } while (choice != 9);
    cout << "\n";
    return 0;
}