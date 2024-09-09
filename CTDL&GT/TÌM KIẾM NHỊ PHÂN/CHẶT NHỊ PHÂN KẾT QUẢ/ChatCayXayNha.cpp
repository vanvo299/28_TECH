/*
CHẶT CÂY XÂY NHÀ

Đề: Bob là 1 thợ mộc tài hoa. Hiện tại anh đang có kế hoạch xây dựng một căn nhà toàn bộ bằng gỗ. Biệt thự được xây bởi các khúc gỗ khác nhau và tổng độ dài của các thanh gỗ là L.
Để lấy các khúc gỗ đó, anh ấy cần vào rừng và chặt cây. Khu rừng gẩn chỗ anh có N cây với độ cao khác nhau. Bob sẽ dùng một cái máy cưa đặc biệt, nó có thể cắt một lượt qua tất cả

Đầu tiên, anh ấy sẽ chọn một độ cao cố định là H, sau đố dùng máy cưa đặc biệt để cắt một đường theo độ cao H này trên các cây có độ cao lớn H
Ví dụ: các cây có độ cao lần lượt là: 10, 16, 17, 15. Chọn H = 15. Do đó cây thứ 2, 3 sẽ được cắt và tổng độ dàu các khúc gỗ thu được là 1 + 2 = 3

Cho độ cao của các ây trong rừng và giá tri trị L (Tổng độ dài cảu các khúc gỗ cần). Hãy giúp Bon tìm giá trị lớn nhất của H thỏa mản rằng Bob chỉ cần dùng máy cắt đúng một lượt để thu 
được số các khúc gỗ cần thiết.

CHÚ Ý: Tổng độ dài các khúc gỗ có thỏa mãn có thể lớn hơn L (Hay nói các khác L <= Tổng độ dài)
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(int a[], int n, int L, ll H)
{
    ll tongGo = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > H) {
            tongGo += (a[i] - H);
        }
    }
    return tongGo >= L;
}
int main()
{
    int n, L; cin >> n >> L;
    int a[n];
    for (int &x : a) cin >> x;
    ll left = 0, right = *max_element(a, a + n);
    ll ans = -1;

    while(left <= right) {
        ll mid = (left + right) / 2;

        if (check(a, n, L, mid)) {
            // dang thua go => cat cao len
            ans = mid;
            left = mid + 1;
        }
        else {
            // dang thieu go => cat thap xuong
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}