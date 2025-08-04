#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream logfile("log.txt", ios::app);
    char a[100];
    cout << "\nEnter your value: ";
    cin >> a;
    logfile << a << endl;
    return 0;
}