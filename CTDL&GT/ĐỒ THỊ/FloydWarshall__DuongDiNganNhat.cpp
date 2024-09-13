/*
[GRAPH]. Thuật toán Floyd Warshall - Tìm đường đi ngắn nhất

- Khác với thuật toán Dijkstra và Bellman-Ford áp dụng để tìm đường đi ngắn nhất từ 1 đỉnh
tới mọi đỉnh còn lại trên đồ thị (SSSP - Single source shortest path), Floyd được áp dụng để
tìm đường đi ngứn nhất giữa mọi cặp đỉnh trên đồ thị (All-pair Shortest Path). Thuật toán 
áp dụng cho đồ thị có hướng, vô hướng không có chu trình âm (Có thể có cạnh âm)
- ĐỘ PHỨC TẠP: O(V^3)

*** CHÚ Ý: Thông thường Floyd chỉ áp dụng cho đồ thị nhỏ có V <= 400
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, a[105][105];

void Nhap()
{
    // Khởi tạo
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) a[i][j] = 0;
            else a[i][j] = 1e9;
        }
    }

    // Nhập
    for (int i = 0; i < m; i++) {
        int x, y, z; 
        cin >> x >> y >> z;
        a[x][y] = z;
        a[y][x] = z;
    }
}

void Floyd_Warshall()
{
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
}
int main()
{
    Nhap();
    Floyd_Warshall();
    int q; cin >> q;
    while(q--) {
        int x, y; 
        cin >> x >> y;
        cout << a[x][y] << endl;
    }
}