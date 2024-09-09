/*
[Mảng cộng dồn - Mảng hiệu]. Bài 3: Thu hoạch cà rốt

Đề: Tèo hiện tại đã bỏ nghề lập trình viên và trở về quê trồng rau nuôi cá, anh ta có một mảnh vườn hình chữ 
nhật có kích thước NxM. Anh ta chia vườn của mình thành NxM ô vuông và trồng vào đó một cây cà rốt, tới vụ
thu hoạch có những cây cà rốt bị chết và có những cây cà tốt có củ, anh ta muốn biết với mỗi mảnh vườn hình 
chữ nhật bắt đầu từ hàng x1 tới hàng x2 và từ cột y1 tới cột y2 thì số cà rốt thu hoạch được là bao nhiêu.

Biết rằng mảnh vườn được mô tả bởi một ma trận nhị phân, 0 tương ứng với cây cà rốt chết và 1 tương ứng
với cây cà rốt có củ.
*/
#include <iostream>
using namespace std;

using ll = long long;

int A[1005][1005];
ll pre[1005][1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }

    // xay dung mang cong don trong mang 2 chieu
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + A[i][j];
        }
    }
    int q; cin >> q;
    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        cout << pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1] << endl;

    }
    return 0;
}