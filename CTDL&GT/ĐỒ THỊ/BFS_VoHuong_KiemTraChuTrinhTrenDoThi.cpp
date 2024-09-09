/*
[GRAPH]. Kiểm tra chu trình trên đồ thị vô hướng - BFS

=> Để kiểm tra chu trình trên đồ thị ta kiểm tra trên đồ thị
có cạnh ngược hay không 

*/
#include <bits/stdc++.h>
using namespace std;

int n, m; // Đỉnh, cạnh
int ok = 0;
bool visited[1005];
vector<int> adj[1005];
int parent[1005];

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        // duyet danh sach ke cua dinh v ma chua duoc tham
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
            else if (v != parent[u]) {
                ok = 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(1);
    if (ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}