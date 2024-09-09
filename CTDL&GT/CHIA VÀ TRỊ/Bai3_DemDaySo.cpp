/*
[Chia và trị]. Bài 3. Đếm dãy số

Đề: Cho số nguyên dương n, bạn được phép sử dụng không giới hạn các số tự nhiên từ 1 đến n.
Hỏi có bao nhiêu cách chọn ra 1 dãy có tổng các phần tử bằng n.
*/

// Dựa vào bài toán chia kẹo Euler
#include <bits/stdc++.h>
using namespace std;

using ll = long long; 
ll mod = 1e9 + 7;

ll Binpow(ll n, ll m) 
{
    if (m == 0) return 1;
    ll tmp = Binpow(n, m / 2);
    
    if (m % 2 == 0) {
        return tmp * tmp  % mod;
    }
    else return (tmp * tmp  % mod) * (n % mod) % mod;
}

int main()
{
    ll n; cin >> n;
    cout << Binpow(2, n - 1);
    return 0;
}