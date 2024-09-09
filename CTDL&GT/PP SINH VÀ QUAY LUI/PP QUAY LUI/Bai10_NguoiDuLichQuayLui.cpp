/*
[Quay lui - Nhánh cận]. Bài 10. Người du lịch

Đề: Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông hai chiều giữa chúng, mạng lưới giao 
thông này được cho bởi mảng C[1...n, 1...n] ở đây C[i][j] = C[j][i] là chi phí đi đoạn đường trực tiếp từ thành phố
i đến thành phố j. Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi
thành phố đúng 1 lần và cuối cùng quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.
*/

// CODE BẰNG PP QUAY LUI


#include <bits/stdc++.h>
using namespace std;

int n, C[100][100], X[100], ans = INT_MAX;
int dis = 0; // luu chi phi duong di giua cac thanh pho
int visited[100]; // mang danh dau thanh pho da di qua
// X[i] = j : thành phố thứ i tôi đi qua là thành phố j

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (visited[j] == 0) {
            X[i] = j;
            visited[j] = 1;
            dis += C[X[i - 1]][X[i]];
            if (i == n) {
                // cap nhat ket qua
                ans = min(ans, dis + C[X[n]][1]);
            } else {
                Try(i + 1);
            }
            visited[j] = 0; // backtrack
            dis -= C[X[i - 1]][X[i]]; // backtrack
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> C[i][j];
        }
    }
    X[1] = 1;
    visited[1] = 1;
    Try(2);
    cout << ans << endl;
    return 0;
}