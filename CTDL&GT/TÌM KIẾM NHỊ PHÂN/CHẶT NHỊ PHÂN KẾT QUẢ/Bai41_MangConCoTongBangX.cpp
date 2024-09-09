/*
[Sắp xếp - Tìm kiếm]. Bài 41. Mảng con có tổng bằng X

Đề: Cho một mảng gồm n số nguyên dương, nhiệm vụ của bạn là đếm số mảng con (dãy con các phần tử liên tiếp) có tổng bằng X

*/

// cac so trong mang khong am
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main()
{
    int n, x; cin >> n >> x;
    int a[n];
    for (int &x : a) cin >> x;
    ll tong = 0;
    map<ll, int> mp;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i];
        if (tong == x) ++ans;
        if (mp.count(tong - x)) ++ans;
        mp[tong] = 1;
        // mp[tong]++; // TH cac so trong mang co so am
    }
    cout << ans << endl;
    return 0;
}