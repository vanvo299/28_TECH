/*
[Sắp xếp - Tìm kiếm]. Bài 34. Căn hộ

Đề: Có n người nộp đơn và m căn hộ miễn phí. Nhiệm vụ của bạn là phân phối các căn hộ sao cho càng nhiều
người đăng ký sẽ nhận được căn hộ càng tốt. Mỗi người nộp đơn có một kích thước căn hộ mong muốn, và họ
sẽ chấp nhận bất kỳ căn hộ nào có diện tích đủ gần với kích thước mong muốn.
*/
#include <bits/stdc++.h>
using  namespace std;

int main()
{
    int n, m, k; cin >> n >> m >> k;
    int i = 0, j = 0, count = 0;
    int nguoi[n], canHo[m];

    for (int &x : nguoi) cin >> x;
    for (int &y : canHo) cin >> y;

    sort(nguoi, nguoi + n);
    sort(canHo, canHo + m);

    while(i < n && j < m) {
        if (abs(nguoi[i] - canHo[j]) <= k) {
            ++i; ++j; ++count;
        }
        else if (nguoi[i] < canHo[j]) ++i; 
        else ++j;
    }
    cout << count << endl;

    return 0;
}

