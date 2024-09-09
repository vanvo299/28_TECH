/*
[GRAPH]. Thuật toán Tanjan - CẠNH CẦU

- Điều kiện để cạnh U, V là cạnh cầu: disc[u] < low[v], trong trường hợp này 
không tồn tại dấu bằng, vì nếu u là gốc của chu trình chứa v thì loại bỏ u, v
sẽ không làm tăng số thành phần liên thông của đồ thị.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, timer = 0;
vector<int> adj[1005];
int disc[1005], low[1005];
bool visited[1005];
vector<pair<int, int>> bridge;

void nhap()
{
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u, int parent)
{
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (disc[u] < low[v]) {
                bridge.push_back({u, v});
            }
        }
        else {
            low[u] = min(low[u], disc[v]);
        }
    }
}
int main()
{
    nhap();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i, -1);
        }
    }
    cout << endl;
    for (pair<int, int> e : bridge) {
        cout << e.first << ' ' << e.second << endl;
    }
    return 0;
}