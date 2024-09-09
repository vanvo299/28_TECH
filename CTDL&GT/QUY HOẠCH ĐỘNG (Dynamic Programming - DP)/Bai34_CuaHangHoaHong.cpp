/*
[DP]. Bài 34. Cửa hàng hoa hồng

Đề: Có hoa hồng trong một cửa hàng. Mỗi bông hồng được chỉ định một ID. Những bông hồng 
này được sắp xếp theo thứ tự 1, 2, 3,..., n. Mỗi bông hồng có một hệ số mùi được ký hiệu là
smell[i]. Bạn muốn mua hoa hồng ở cửa hàng này với điều kiện phải mua hoa hồng theo 
phân khúc. Nói cách khác, bạn có thể mua hoa hồng từ l đến r. Bạn có thể loại bỏ
nhiều nhất một hoa hồng khỏi phân đoạn hoa hồng này. Như vậy, chiều dài cuối cùng của 
hoa hồng là n hoặc n - 1. Nhiệm vụ của bạn là tính toán độ dài tối đa có thể có của dãy liền
kề tăng dần các hệ số mùi của những hoa hồng này.

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int smell[n + 1], F[n + 1] = {0}, G[n + 1] = {0};
    for (int i = 1; i <= n; i++) cin >> smell[i];
    int res = 1;

    // xét dãy tăng liên tiếp
    F[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (smell[i] > smell[i - 1]) F[i] = F[i - 1] + 1;
        else F[i] = 1;
        res = max(res, F[i]);
    }

    // xét dãy giảm liên tiếp
    G[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        if (smell[i] < smell[i + 1]) G[i] = G[i + 1] + 1;
        else G[i] = 1;
        res = max(res, G[i]);
    }

    for (int i = 1; i <= n; i++) {
        cout << F[i] << ' ';
    }
    cout << endl;
        for (int i = 1; i <= n; i++) {
        cout << G[i] << ' ';
    }

    // lựa chọn xóa từng số 
    for (int i = 2; i <= n - 1; i++) {
        if (smell[i - 1] < smell[i + 1]) {
            res = max(res, F[i - 1] + G[i + 1]);
        }
    }
    cout << endl << res << endl;

    return 0;
}