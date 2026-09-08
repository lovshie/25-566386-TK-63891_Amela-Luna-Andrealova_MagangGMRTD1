/*
    Nama : Amela Luna Andrealova
    NIM  : 25/566386/TK/63891
*/

#include <iostream>
using namespace std;

int main() {
    long long n, m, k;
    cout << "Masukkan jumlah barang berat (n): ";
    cin >> n;
    cout << "Masukkan jumlah barang ringan (m): ";
    cin >> m;
    cout << "Masukkan kapasitas truk (k): ";
    cin >> k;

    if (n % 3 != 0 || m % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    long long X = n / 3;
    long long Y = m / 3;
    long long capHeavy = k / 2;
    long long capLight = k;

    auto hitungLangkah = [](long long X, long long cap) -> long long {
        if (X == 0) return 0;
        if (cap == 0) return -1;

        long long q = X / cap;
        long long r = X % cap;
        long long total = 4 * q;

        if (r > 0) {
            if (2 * r <= cap) {
                total += 3;
            } else {
                total += 4;
            }
        }

        return total;
    };

    long long stepsBerat = hitungLangkah(X, capHeavy);
    long long stepsRingan = hitungLangkah(Y, capLight);

    if (stepsBerat == -1 || stepsRingan == -1) {
        cout << -1 << endl;
    } else {
        cout << stepsBerat + stepsRingan << " langkah" << endl;
    }

    return 0;
}