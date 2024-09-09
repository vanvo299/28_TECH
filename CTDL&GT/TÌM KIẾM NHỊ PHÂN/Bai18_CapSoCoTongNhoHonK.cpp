/*
[Sắp xếp - Tìm kiếm]. Bài 18. Cặp số có tổng nhỏ hơn K

Đề: Cho mảng a gồm n phần tử và số nguyên dương k. Đếm số lượng cặp số ai, aj (i != j) có tổng nhỏ hơn k

*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a + n);
    long long count = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(a + i + 1, a + n, k - a[i]);
        it--;
        count += it - (a + i);
    }
    cout << count << endl;
    return 0;
}