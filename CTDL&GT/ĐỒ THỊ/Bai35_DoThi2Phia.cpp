/*
[GRAPH]. Bài 35. Đồ thị 2 phía (Bipartite graph)

ĐỀ: Trong lý thuyết đồ thị, đồ thị hai phía là một đồ thị đặc biệt, trong đó tập các đỉnh có thể
được chia thành hai tập không giao nhau thỏa mãn điều kiện không có cạnh nối hai đỉnh
bất kỳ thuộc cùng một tập. Cho đồ thị vô hướng G = (V, E), hãy kiểm tra xem đồ thị đã cho 
có phải là đồ thị 2 phía không ?
*/

// 1, 2 => color
// 0 => false
#include <bits/stdc++.h>
using namespace std;

int n, m, color[1005];
vector<int> adj[1005];
bool visited[1005];
int ok = 1;

void DFS(int u)
{
    for (int v : adj[u]) {
        if (color[v] == 0) {
            // chưa có màu
            color[v] = 3 - color[u];
            DFS(v);
        }
        else if (color[v] == color[u]) {
            // có màu rồi
            ok = 0;
            return; // không phải đồ thị 2 phía
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            color[i] = 1;
            DFS(1);
        }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}