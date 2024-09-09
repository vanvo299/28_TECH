/*
[Mảng 2 chiều]. Bài 20. Tìm đường đi

Đề: Cho một ma trận nhị phân có N hàng và M cột, một con chuột bắt đầu từ ô có tọa độ [s, t] và tìm đường đi tới
ô [u, v], biết rằng ở mỗi bước con chuột có thể di chuyển từ ô hiện tại sang các ô chung cạnh với ô hiện và 
số ở ô chung cạnh là số 1. Bạn chỉ được đi qua 1 ô đúng 1 lần hãy kiểm tra xem con chuột có thể tìm được 
đường đi tới ô [u, v] hay không ? Dữ liệu đảm bao 2 ô [s, t] và ô [u, v] đều bằng 1.

*/
#include <bits/stdc++.h>
using namespace std;

int n, m, s, t, u, v;
int a[100][100];

void nhap()
{
    cin >> n >> m;
    cin >> s >> t >> u >> v; // s,t,u,v bat dau tu 1
    --s; --t; --u; --v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void move(int i, int j)
{
    a[i][j] = 0;
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1]) {
            move(i1, j1);
        }
    }
}
int main()
{
    nhap();
    move(s, t);
    if (a[u][v] == 0) cout << "YES\n";
    else cout << "NO";
    return 0;
}