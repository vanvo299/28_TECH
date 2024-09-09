/*
[GRAPH]. Kiểm tra chu trình trên đồ thị vô hướng - DFS

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

bool DFS(int u)
{
    visited[u] = true;
    // duyet ds ke cua dinh u
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            // if (DFS(v)) return true;
            DFS(v);
        }
        else if (v != parent[u]) {
            // return true;
            ok = 1;
        }
    }
    // return false;
}
int main()
{
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    // if (DFS(1)) cout << "YES\n";
    // else cout << "NO\n";
    DFS(1);
    if (ok) cout << "YES\n"; 
    else cout << "NO\n"; // khong co chu trinh
    return 0;
}