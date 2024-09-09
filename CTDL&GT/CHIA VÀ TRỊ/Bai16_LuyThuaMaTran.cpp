/*
[Chia và trị]. Bài 16. Lũy thừa ma trận 2

Đề: Cho ma trận vuông A[][] kích thước N * N. Nhiệm vụ của bạn là hãy tính ma trận A^K vói K
là số nguyên cho trước. Sau đó, tính tổng các phần tử của cột cuối cùng. Đáp số có thể rất
lớn, hãy in ra kết quả theo modulo 10^9 + 7
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod = 1e9 + 7;
ll n, k;

struct Matrix {
    ll F[15][15];
};

Matrix operator * (Matrix a, Matrix b)
{
    Matrix c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c.F[i][j] = 0;
            for (int k= 0; k < n; k++) {
                c.F[i][j] += (a.F[i][k] * b.F[k][j]) % mod;
                c.F[i][j] %= mod;
            }
        }
    }
    return c;
}

Matrix powMod(Matrix a, ll n)
{
    if (n == 1) return a;
    Matrix x = powMod(a, n / 2);

    if (n % 2 == 0) {
        return x * x;
    } else return x * x * a;
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
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += res.F[i][n - 1];
        sum %= mod;
    }
    cout << sum << endl;
    return 0;
}