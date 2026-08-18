#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    string received;
    cout << "Enter the received codeword: ";
    cin >> received;
    int n = received.length();
    vector<int> codeword(n + 1);
    for (int i = 0; i < n; i++) {
        codeword[n - i] = received[i] - '0';
    }
    int r = 0;
    while (pow(2, r) < n + 1) {
        r++;
    }
    cout << "\n Receiver Side:\n";
    cout << "Codeword received: " << received << endl;
    cout << "Redundant bits received:\n";
    for (int i = 0; i < r; i++) {
        int position = pow(2, i);
        cout << "R" << position << " = "
             << codeword[position] << endl;
    }
    int errorPosition = 0;
    cout << "\n check results:\n";
    for (int i = 0; i < r; i++) {
        int parityPosition = pow(2, i);
        int parity = 0;
        for (int j = 1; j <= n; j++) {
            if (j & parityPosition) {
                parity ^= codeword[j];
            }
        }
        cout << "R" << parityPosition << " = " << parity << endl;
        if (parity == 1) {
            errorPosition += parityPosition;
        }
    }
    if (errorPosition == 0) {
        cout << "\nError is NOT present." << endl;
    }
    else {
        cout << "\nError IS present." << endl;
        cout << "Error is at position: "
             << errorPosition << endl;
        codeword[errorPosition] ^= 1;
    }
    cout << "\n correct codeword: ";
    for (int i = n; i >= 1; i--) {
        cout << codeword[i];
    }
    cout << endl;
    return 0;
}
