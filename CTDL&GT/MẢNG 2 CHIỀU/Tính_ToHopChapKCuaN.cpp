/*
Tính tổ hợp chập K của N bằng mảng 2 chiều
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll C[1005][1005];
int mod = 1e9 + 7;

void ktao()
{
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] %= mod;
            }
        }
    }
}
int main()
{
    ktao();
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= i; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}