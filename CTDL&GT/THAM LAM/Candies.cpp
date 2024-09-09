/*
[Tham lam]. Candies

Đề: Alice is a kindergarten teacher. She wants to give some candies to the children in her class. All the children sit
in a line and each of them has a rating score according to his or her performance in the class. Alice wants to
give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating
must get more candies. Alice wants to minimize to total number of candies she must buy.

Dịch: Alice là một giáo viên mẫu giáo. Cô muốn tặng một số kẹo cho các em học sinh trong lớp của mình. Tất cả các em đều 
ngồi thành một hàng và mỗi em đều có một điểm số đánh giá theo kết quả học tập của mình trong lớp. 
Alice muốn tặng ít nhất 1 viên kẹo cho mỗi em. Nếu hai em ngồi cạnh nhau, thì em nào có điểm số cao hơn phải nhận được 
nhiều kẹo hơn. Alice muốn tối thiểu hóa tổng số kẹo mà cô phải mua.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    int res[n];
    res[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            res[i] = res[i - 1] + 1;
        }
        else res[i] = 1;
    }

    for (int i = n - 2; i >= 0; i--) {
        int tmp = res[i];
        if (a[i] > a[i + 1]) {
            res[i] = res[i + 1] + 1;
        }
        res[i] = max(tmp, res[i]);
        // res[i] là số kẹo hiện tại ở chiều nghịch, tmp là kẹo đã lưu ở chiều thuận, nên cần lấy số max 2 số kẹo này
    }

    ll ans = 0; // tổng số kẹo cô giáo cần
    for (int x : res) {
        ans += x;
    }
    cout << ans << endl;
    return 0;
}