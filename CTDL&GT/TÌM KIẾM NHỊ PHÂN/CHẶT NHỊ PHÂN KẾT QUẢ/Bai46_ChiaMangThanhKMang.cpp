/*
[Sắp xếp - Tìm kiếm]. Bài 46. Chia mảng thành k mảng con liên tiếp có tổng lớn nhỏ nhất

Đề: Bạn được ccung cấp một mảng chứa n số nguyên dương. Nhiệm vụ của bạn là chia mảng thành k mảng con
liên tiếp sao cho tổng lớn nhất trong một mảng con càng nhỏ càng tốt (Gợi ý sử dụng binary search on
answer. Binary search trên tổng lớn nhất của 1 mảng con).
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(int a[], int n, int k, ll sum) 
{
    int dem = 0;
    ll tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i];
        if (tong > sum) {
            ++dem;
            tong = a[i];
        }
    }
    ++dem;
    return dem <= k;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    ll right = 0;
    for (int &x : a) {
        cin >> x;
        right += x;
    }
    ll left = *max_element(a, a + n);
    ll ans = -1;
    while(left <= right) {
        ll mid = (left + right) / 2;
        if (check(a, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}