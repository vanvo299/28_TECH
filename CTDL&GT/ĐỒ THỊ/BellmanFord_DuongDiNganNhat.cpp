/*
[GRAPH]. Thuật toán Bellman-Ford - Tìm đường đi ngắn nhất

- Thuật toán Bellman-Ford được sử dụng để tìm đường đi ngắn nhất từ 1 đỉnh tới
mọi đỉnh còn lại trên đồ thị, khác với Dijkstra thì Bellman-Ford có thể áp dụng cho 
đồ thị với cạnh có trọng số âm, tuy nhiên không thể áp dụng nếu như đồ thị có chu
trình âm. Thuật toán này có thể sử dụng để xác định rằng đồ thị có chu trình âm.
- Độ phức tạp: O(V * E)

** Ý tưởng thuật toán: 
- Ban đầu ta sử dụng một mảng d[] để lưu khoảng cách từ đỉnh nguồn s tới mọi đỉnh còn lại
trên đồ thị, d[s] = 0 và d[u] = INF (vô cùng lớn) với mọi đỉnh u còn lại trên đồ thị
- Thuật toán lặp n - 1 bước, mỗi bước sẽ xét tất cả các cặp cạnh (u, v) có trọng số w. 
Nếu d[v] > d[u] + w thì sẽ cập nhật d[v].

*/
#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;
int n, m, s;
vector<pair<int, int>> adj[1005]; // first : w, second : u 
int d[1005];

void nhap()
{
    s = 1;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int x, y, w; 
        cin >> x >> y >> w;
        adj[x].push_back({w, y});
        adj[y].push_back({w, x});
    }
}

void BellmanFord(int s)
{
    for (int i = 1; i <= n; i++) {
        d[i] = 1e9;
    }
    d[s] = 0;
    for (int i = 0; i < n-1; i++) {
        for (int u = 1; u <= n; u++) {
            // Duyệt từng đỉnh và duyệt danh sách kề của từng đỉnh
            for (auto it : adj[u]) {
                int v = it.second, khoangCach = it.first;
                d[v] = min(d[v], d[u] + khoangCach);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
}

int main()
{
    nhap();
    BellmanFord(s);
    return 0;
}