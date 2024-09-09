/*
[Hàm bổ sung]. Bài 7. Tích chia dư

Đề: Cho N số nguyên, bạn hãy tính tích các số này và chia dư tổng cho 1o^9 + 7
*/

#include <iostream>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    ll mod = 1e9+7;
    ll kq = 1;
    for (int i = 1; i < n; i++) {
        ll tmp; cin >> tmp;
        kq *= tmp;
        kq %= mod;
    }
    cout << kq << endl;
    return 0;
}