/*
[DP]. Bài 6. Frop SPOJ

Đề: Một con ếch có thể nhảy 1, 2, 3 bước để có thể lên đến một đỉnh cần đến. Hãy đếm số các
cách con ếch có thể nhảy đến đỉnh
*/
#include <bits/stdc++.h>
using namespace std;

int F[1001];

int main()
{
    int n; cin >> n;
    F[0] = 1;
    int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i >= j) {
                F[i] += F[i - j];
            }
            F[i] %= mod;
        }
    }
    cout << F[n];
    return 0;
}