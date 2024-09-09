/*
[Chia và trị]. bài 15. Lũy thừa ma trận

Đề: Cho ma trận A[][] là ma trận vuông cỡ N x N. Hãy tính kết quả A^K  và chia dư cho các phần tử 
trong ma trận kết quả cho 10^9 + 7
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

    ll n, k;

struct Matrix {
    ll F[15][15];
};

ll mod = 1e9 + 7;

Matrix operator * (Matrix a, Matrix b)
{
    Matrix c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c.F[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c.F[i][j] += (a.F[i][k] * b.F[k][j]) % mod;
                c.F[i][j] %= mod;
            } 
        }
    }
    return c;
}

Matrix powMod(Matrix a, int n)
{
    if (n == 1) return a;
    Matrix x = powMod(a, n / 2);

    if (n % 2 == 0) {
        return x * x;
    }
    else return x * x * a;
}
int main()
{
    cin >> n >> k;
    Matrix a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a.F[i][j];
        }
    }
    Matrix res = powMod(a, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res.F[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}