/*
[Graph]. Bài 10. DFS trên đồ thị có hướng

Đề: Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy thực hiện duyệt in 
ra danh sách các đỉnh được duyệt theo thuật toán DFS, đỉnh bắt đầu được cho sẵn

*/
#include <bits/stdc++.h>
using namespace std;

int n, m, s; // Đỉnh, cạnh, đỉnh bắt đầu duyệt
vector<int> adj[1005];
bool visited[1005];

void DFS(int u)
{
    cout << u << ' ';
    visited[u] = true;
    // duyet ds ke cua dinh u
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}
int main()
{
    cin >> n >> m >>  s;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    DFS(s);

    return 0;
}