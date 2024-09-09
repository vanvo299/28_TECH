// Tính lũy thừa bằng Lũy thừa nhị phân
#include <bits/stdc++.h>
using namespace std;

using ll = long long;


// Hàm tính (a^b) % c
ll binpow1(ll a, ll b, ll c) 
{
    if (b == 0) return 1;

    // Tinh a ^ (b / 2)
    ll x = binpow1(a, b / 2, c);
    if (b % 2 == 0) {
        return (x%c) * (x%c) % c;
    } else {
        return (x%c) * (x%c) * (a%c) % c;
    }
}

// Hàm tính a ^ b
double binpow(double a, ll b) 
{
    if (b == 0) return 1;

    if (b < 0) {
        a = 1 / a;
        if (b == INT_MIN) {
            b = INT_MAX;
            a *= a;
        } else {
            b = -b;
        }
    }
    // Tinh a ^ (b / 2)
    double x = binpow(a, b /2);
    if (b % 2 == 0) {
        return x * x;
    } else {
        return x * x * a;
    }
}
int main()
{
    cout << binpow(2, -2) << endl;
    cout << binpow1(2, 1000000000, 10);
    return 0;
}