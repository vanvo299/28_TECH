/*
[Chia và trị]. Bài 5. Xâu Fibo

Đề: Xâu S chỉ bao gồm các kí tự A và B được gọi là xâu Fibonacci nếu S(1) = 'A', S(2) = 'B', S(n) = S(n - 2) + S(n - 1),
trong đó phép + là phép nối 2 xâu. Bài toán đặt ra là tìm kí tự thứ K trong xâu fibonacci thứ N.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll F[100];

void ktao()
{
    F[1] = 1; F[2] = 1;
    for (int i = 3; i <= 92; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
}

char Fibo(int n, ll k)
{
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (k <= F[n - 2]) {
        return Fibo(n - 2, k);
    }
    else {
        return Fibo(n - 1, k - F[n - 2]);
    }
}
int main()
{
    ktao();
    ll n, k; cin >> n >> k;
    cout << Fibo(n, k) << endl;
    return 0;
}