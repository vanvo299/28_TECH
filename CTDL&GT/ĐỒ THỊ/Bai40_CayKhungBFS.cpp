/*
[GRAPH]. Bài 39. Cây khung BFS

ĐỀ: Cho đồ thị vô hướng G = (V, E) liên thông. Hãy in ra các cạnh của cây khung này theo thuật 
toán BFS bắt đầu từ đỉnh s. Thứ tự mở rộng cây khung của thuật toán BFS luôn mở rộng 
đỉnh có thứ tự nhỏ nhất trước.

*/
#include <bits/stdc++.h>
using namespace std;

int n, m, start; // Đỉnh, cạnh, đỉnh bắt đầu
vector<int> adj[1005];
bool visited[1005];

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                cout << u << "->" << v << endl;
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    BFS(start);
    return 0;
}