/*
[Sắp xếp - Tìm kiếm]. Bài 32. BerSU Ball

Đề: Đại học bang Berland đang tổ chức một buổi khiêu vũ trong lễ kỷ niệm 100500 năm thành lập. Có n các chàng
trai và m cô gái đã bận rộn tập luyện các động tác nhảy múa. Chúng tôi biết rằng một số cặp nam và nữ sẽ
được mời tham gia vũ hội. Tuy nhiên, kỹ năng khiêu vũ của các đối tác trong mỗi cặp khác nhau nhiều nhất là
một đơn vị. Đối với mỗi cậu bé, chúng tôi biết kỹ năng nhảy của cậu ấy. Tương tự, đối với mỗi cô gái, chúng tôi
biết kỹ năng khiêu vũ của cô ấy. Viết mã xác định số cặp lớn nhất có thể được hình thành từ n trai và m gái.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i = 0, j = 0;
    int a[n], b[m];

    for (int &x : a) cin >> x;
    for (int &y : b) cin >> y;

    sort(a, a + n);
    sort(b, b + m);

    int count = 0;
    while(i < n && j < m) {
        if (abs(a[i] - b[j]) <= 1) {
            ++i; ++j; ++count;
        }
        else if (a[i] < b[j]) ++i;
        else ++j;
    }
    cout << count << endl;
    return 0;
}