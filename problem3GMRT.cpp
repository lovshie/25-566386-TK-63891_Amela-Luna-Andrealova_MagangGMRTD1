/*
    Nama : Amela Luna Andrealova
    NIM  : 25/566386/TK/63891
*/

#include <iostream>
using namespace std;

int main() {
    int A[9]; // index 1 sampai 8 dipakai
    for (int i = 1; i <= 8; i++) {
        cin >> A[i];
    }

    bool bisaSemua = false;

    for (int start = 1; start <= 8; start++) {
        if (bisaSemua) break; // opsional, untuk efisiensi

        bool dikunjungi[9] = {false}; // index 1 sampai 8 dipakai
        int current = start;
        int jumlahDibuka = 0;

        while (current != 0 && !dikunjungi[current]) {
            dikunjungi[current] = true;
            jumlahDibuka++;
            current = A[current];
        }

        if (jumlahDibuka == 8) {
            bisaSemua = true;
        }
    }

    if (bisaSemua) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}