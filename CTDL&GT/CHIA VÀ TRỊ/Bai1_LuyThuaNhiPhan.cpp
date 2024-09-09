/*
[Chia và trị]. Bài 1. Lũy thừa nhị phân

Đề:  Nhiệm vụ của bạn là tính N^K, kết quả được chia dư với 10^9 + 7;
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9 + 7;

ll BinPow(ll a, ll b) 
{
    if (b == 0) return 1;

    ll x = BinPow(a, b / 2);
    if (b % 2 == 0) {
        return (x % mod) * (x % mod) % mod;
    }
    else {
        return ((x % mod) * (x % mod) % mod) * (a % mod) % mod;
    }
}
int main()
{
    ll n, k; cin >> n >> k;
    cout << BinPow(n, k) << endl;
    return 0;
}