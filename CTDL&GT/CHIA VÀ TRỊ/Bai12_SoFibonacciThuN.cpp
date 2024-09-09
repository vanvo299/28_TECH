/*
[Chia và trị]. Bài 12. Số fibonacci thứ N

Đề: Tìm số Fibonacci thứ N sau khi chia dư cho 10^9 + 7
*/

/*
- Công thức: (1 1)
             (1 0)  
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Matrix {
    ll f[2][2];
};

ll mod = 1e9 + 7;

// Định nghĩa toán tử * để nhân 2 ma trận
Matrix operator * (Matrix a, Matrix b)
{
    Matrix c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c.f[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                c.f[i][j] += (a.f[i][k] * b.f[k][j]) % mod;
                c.f[i][j] %= mod;
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
    } else return x * x * a;
}

int main()
{
    ll n; cin >> n;
    Matrix a;
    a.f[0][0] = a.f[0][1] = a.f[1][0] = 1;
    a.f[1][1] = 0;

    Matrix res = powMod(a, n);
    cout << res.f[0][1] << endl;
    return 0;
}