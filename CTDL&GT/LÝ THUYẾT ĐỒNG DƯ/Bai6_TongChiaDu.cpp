/*
[Hàm bổ sung]. Bài 6. Tổng chia dư

Đề: Cho N số nguyên, bạn hãy tính tổng các số này và chia dư tổng cho 10^9 + 7 (1000000007)
*/
#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    int n; cin >> n;
    ll mod = 1e9 + 7;
    ll kq = 0;
    for (int i = 0; i < n; i++) {
        ll tmp; cin >> tmp;
        kq += tmp;
        kq %= mod;
    }
    cout << kq << endl;
    return 0;
}