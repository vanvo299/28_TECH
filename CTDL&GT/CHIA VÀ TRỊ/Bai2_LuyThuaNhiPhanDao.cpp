/*
[Chia và trị]. Bài 2. Lũy thừa nhị phân đảo

Đề: Cho số nguyên dương N, gọi M là số đảo của N. Hãy tính lũy thừa cơ số N và số mũ M và chia dư
kết quả cho 10^9 + 7

vd về số đảo; N = 123 => M = 321
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9 + 7;

// Hàm đảo số (VD: 123 => 321)
ll dao_number(ll n)
{
    string s = to_string(n);
    for (int i = 0; i < s.size() / 2; i++) {
        swap(s[i], s[s.size() - i - 1]);
    }
    return  stoll(s);
}

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
    cout << Binpow(n, dao_number(n)) << endl;
    
    return 0;
}