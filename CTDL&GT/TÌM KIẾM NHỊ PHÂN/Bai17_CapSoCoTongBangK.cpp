/*
[Sắp xếp - Tìm kiếm]. Bài 17. Cặp số có tổng bằng K

Đề: Cho mảng a gồm n phần tử và số nguyên dương k. Đếm số lượng cặp số Ai, Aj (i != j) có tổng bằng K

Gợi ý: Sắp xếp mảng tăng dần sau đó đối với mỗi phần tử a[i] trong mảng tìm xem trong đoạn (i + 1, n - 1) có bao nhiêu
phần tử có giá trị là k - a[i], bằng cách tìm vị trí đầu tiên và vị trí cuối cùng của phần tử có giá trị là k - a[i]
=> số lượng

*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    long long count = 0;
    for (int i = 0; i < n; i++) {
        auto it1 = lower_bound(a + i + 1, a + n, k - a[i]);
        auto it2 = upper_bound(a + i + 1, a + n, k - a[i]);
        count += it2 - it1;
    }
    cout << count << endl;
    return 0;
}