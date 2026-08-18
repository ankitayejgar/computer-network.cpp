#include <iostream>
#include <vector>
#include <string>
using namespace std;
int getRedundantBits(int m)
{
    int r = 0;
    while ((1 << r) < (m + r + 1))
    {
        r++;
    }
    return r;
}
bool isParityPosition(int position)
{
    return (position & (position - 1)) == 0;
}
vector<int> generateHammingCode(string data, int r)
{
    int m = data.length();
    int totalBits = m + r;
    vector<int> code(totalBits + 1, 0);
    int dataIndex = 0;
    for (int position = totalBits; position >= 1; position--)
    {
        if (!isParityPosition(position))
        {
            code[position] = data[dataIndex] - '0';
            dataIndex++;
        }
    }
    for (int i = 0; i < r; i++)
    {
        int parityPosition = 1 << i;
        int parity = 0;
        for (int position = 1; position <= totalBits; position++)
        {
            if ((position & parityPosition) != 0)
            {
                parity ^= code[position];
            }
        }
        code[parityPosition] = parity;
    }
    return code;
}
int main()
{
    string data;
    cout << "Enter Data Word: ";
    cin >> data;
    int m = data.length();
    int r = getRedundantBits(m);
    vector<int> code = generateHammingCode(data, r);
    int totalBits = m + r;
    cout << "\nData Word       : " << data << endl;
    cout<<"total data words bits(m):"<<m<<endl;
    cout << "Redundant Bits(r)  : " << r << endl;
    cout << "Total Bits  (n)    : " << totalBits << endl;
    for (int i = 0; i < r; i++)
    {
        int position = 1 << i;
        cout << "R" << position
             << "              : " << code[position] << endl;
    }
    cout << "Code Word       : ";
    for (int position = totalBits; position >= 1; position--)
    {
        cout << code[position];
    }
    cout << endl;
    return 0;
}
