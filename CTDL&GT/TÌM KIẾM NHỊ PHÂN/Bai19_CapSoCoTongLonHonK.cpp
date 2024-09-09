/*
[Sắp xếp - Tìm kiếm]. Bài 19. Cặp số có tổng lớn hơn K

Đề: Cho mảng a gồm n phần tử và số nguyên dương k. Đếm số lượng cặp số ai, aj (i != j) có tổng lớn hơn k

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

    int count = 0;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(a + i + 1, a + n, k - a[i]);
        count += a + n - it;
    }
    cout << count << endl;
    return 0;
}
