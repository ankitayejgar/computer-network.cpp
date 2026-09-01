#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ip;

    cout << "Enter IPv4 address: ";
    cin >> ip;
    cout << "\nValid IPv4 Address" << endl;
    int first = stoi(ip.substr(0, ip.find('.')));
    cout << "First Byte: " << first << endl;
    if (first <= 127)
    {
        cout << "Class: A" << endl;
        cout << "Net ID: " << ip.substr(0, ip.find('.')) << endl;
        cout << "Host ID: " << ip.substr(ip.find('.') + 1) << endl;
        cout << "Network Address: "
             << ip.substr(0, ip.find('.')) << ".0.0.0" << endl;
    }
    else if (first <= 191)
    {
        cout << "Class: B" << endl;
    }
    else if (first <= 223)
    {
        cout << "Class: C" << endl;
    }
    else if (first <= 239)
    {
        cout << "Class: D" << endl;
    }
    else
    {
        cout << "Class: E" << endl;
    }

    return 0;
}