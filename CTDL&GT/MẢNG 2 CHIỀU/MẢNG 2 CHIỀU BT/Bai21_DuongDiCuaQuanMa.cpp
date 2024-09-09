/*
[Mảng 2 chiều]. Bài 21. Đường đi của quân mã.

Đề: Cho bàn cờ vua N * N các ô trên bàn cờ có giá trị là 0 hoặc 1. Một con mã xuất phát từ ô [s, t] và muốn di
chuyển tới ô [u, v] con mã chỉ có thể di chuyển ở các ô mà tại ô đó có giá trị là 1 và nó có thể di chuyển qua lại
1 ô nhiều lần. Hãy xác định xem con mã có thể tìm được đường đi hay không, dữ liệu đảm bảo ô [s, t] và ô [u, v] 
đều có giá trị là 1.
*/

#include <bits/stdc++.h>
using namespace std;

int n, s, t, u, v;
int a[100][100];

void nhap()
{
    cin >> n;
    cin >> s >> t >> u >> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

int dx[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
int dy[8] = {-1, +1, -2, +2, -2, +2, -1, +1};

void move(int i, int j)
{
    a[i][j] = 0;
    for (int k = 0; k < 8; k++) {
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && a[i1][j1]) {
            move(i1, j1);
        }
    }
}
int main()
{
    nhap();
    move(s, t);
    if (a[u][v] == 0) cout << "YES\n";
    else cout << "NO\n"; 
    return 0;
}