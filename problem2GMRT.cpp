/*
    Nama : Amela Luna Andrealova
    NIM  : 25/566386/TK/63891
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, C, R, K;
    cin >> n >> C >> R >> K;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<int> dp(K + 1, -1);
    dp[0] = C;

    int jawaban = 0;

    for (int i = 0; i < n; i++) {
        vector<int> dpBaru(K + 1, -1);
        bool adaYangBerhasil = false;

        for (int j = 0; j <= K; j++) {
            if (dp[j] == -1) continue;

            // opsi A: tanpa charging
            if (dp[j] >= x[i]) {
                int sisa = dp[j] - x[i];
                if (sisa > dpBaru[j]) dpBaru[j] = sisa;
                adaYangBerhasil = true;
            }

            // opsi B: dengan charging (butuh slot j+1)
            if (j + 1 <= K) {
                int terisi = min(C, dp[j] + R);
                if (terisi >= x[i]) {
                    int sisa = terisi - x[i];
                    if (sisa > dpBaru[j + 1]) dpBaru[j + 1] = sisa;
                    adaYangBerhasil = true;
                }
            }
        }

        dp = dpBaru;

        if (!adaYangBerhasil) break;
        jawaban = i + 1;
    }

    cout << jawaban << endl;

    return 0;
}