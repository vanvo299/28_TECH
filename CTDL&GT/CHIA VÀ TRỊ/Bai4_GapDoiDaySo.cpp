/*
[Chia và trị]. Bài 4. Gấp đôi dãy số

Đề: Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N - 1 phép biến đổi "gấp đôi"
dãy số như sau: Với dãy số A hiện tại, dãy số mới có dạng A, x, A, trong đó x là số tự nhiên
bé nhất chưa xuất hiện trong A.

Ví dụ với 2 bước biến đổi, ta có [1], [1 2 1], [1 2 1 3 1 2 1].
Các bạn hãy xác định số thứ K trong dãy cuối cùng là bao nhiêu
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gapDoi(ll n, ll k)
{
    ll x = pow(2, n - 1);
    if (n == 1) return 1;
    if (k == x) return n;

    if (k < x) return gapDoi(n - 1, k);
    else return gapDoi(n - 1, k - x);
}
int main()
{
    ll n, k; cin >> n >> k;
    cout << gapDoi(n, k);
    return 0;
}