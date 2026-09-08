/*
    Nama : Amela Luna Andrealova
    NIM  : 25/566386/TK/63891
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;

    cout << "Masukkan panjang rangkaian : ";
    cin >> n;
    cout << "Masukkan rangkaian perintah : ";
    cin >> s;

    int counter = 0;
    bool valid = true;

    for (char c : s) {
        if (c == '(') {
            counter++;
        } else if (c == ')') {
            counter--;
        }

        if (counter < 0) {
            valid = false;
            break;
        }
    }

    if (counter != 0) {
        valid = false;
    }

    if (valid) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}