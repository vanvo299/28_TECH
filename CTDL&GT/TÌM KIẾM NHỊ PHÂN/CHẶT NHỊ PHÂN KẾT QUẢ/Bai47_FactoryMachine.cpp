/*
[Sắp xếp - Tìm kiếm]. Bài 47. Factory Machine

Đề: Một nhà máy có n máy có thể được sử dụng để tạo ra sản phẩm. Mục tiêu của bạn là tạo ra tổng số sản phẩm.
Đối với mỗi máy, bạn biết số giây nó cần để tạo ra một sản phẩm. Các máy có thể hoạt động đồng thời và bạn
có thể tự do quyết định lịch trình của chúng. Thời gian ngắn nhất cần thiết để làm ra t sản phẩm là bao nhiêu ?
(Gợi ý: Binary search on answer).
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// ham check xem tai thoi gian nao do tao ra co nhieu hon or bang t san pham ko
bool check(int a[], int n, int t, ll time) 
{
    ll dem = 0;
    for (int i = 0; i < n; i++) {
        dem += time / a[i];
        if (dem >= t) return true;
    } 
    return dem >= t;
}
int main()
{
    int n, t; cin >> n >> t;
    int a[n];

    for (int &x : a) cin >> x;
    // ll left = 0, right = 1ll * (*min_element(a, a + n)) * t;
    ll left = 0, right = 9e18;
    ll ans = -1;

    while(left <= right) {
        ll mid = (left + right) / 2;
        // check mid
        if (check(a, n, t, mid)) {
            ans = mid;
            right = mid - 1; // mid thoa man nen ta chi can xet doan truoc mid
        }
        else {
            left = mid + 1;
        }
    } 
    cout << ans << endl;
    return 0;
}