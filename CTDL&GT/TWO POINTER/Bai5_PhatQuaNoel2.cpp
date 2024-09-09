/*
[Two Pointer]. Bài 5. Phát Quà Noel 2

Đề: Nhân dịp lễ giáng sinh 2022, 28Tech tổ chức phát quà cho các bạn nhỏ. Có N món quà được xếp thành hàng
ngang, mỗi món quà có khối lượng cho trước. Tí là một đứa trẻ không như nhiều đứa trẻ khác. Tí chỉ
muốn chọn ít phần quà càng tốt miễn tổng các phần quà này lớn hơn hoặc bằng S. Tí chỉ có thể lựa chọn các 
phần quà đặt cạnh nhau, bạn hãy xác định xem Tí có thể chọn tối đa bao nhiêu phần quà để tổng khối lượng của
các phần quà lớn hơn hoặc bằng S.

** Input format:
- Dòng đầu tiên là N và S.
- Dong thứ hai là trọng lượng của N phần quà.

Gợi ý :  Bài toán tìm dãy con ngắn nhất có tổng lớn hơn hoặc bằng S
*/

#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    int n, s; cin >> n >> s;
    int a[n];

    for (int &x : a) cin >> x;

    int left = 0, right = 0;
    ll sum = 0, ans = 1e9;

    for (right = 0; right < n; right++) {
        sum += a[right];
        while(sum >= s) {
            ans = right - left + 1;
            sum -= a[left];
            ++left;
        }
    }

    cout << ans << endl;
    return 0;
}