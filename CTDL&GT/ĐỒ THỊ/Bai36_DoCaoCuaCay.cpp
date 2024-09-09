/*
[GRAPH]. Bài 36. Độ cao của cây

ĐỀ: Cho cây với đỉnh gốc là đỉnh 1, các đỉnh của cây được đánh số từ 1 tới n. Độ cao củamoojt
nốt trong cây được tính bằng số cạnh trên đường đi ngắn nhất giữa nốt này tới đỉnh gốc.
Như vậy, gốc của cây là đỉnh 1 sẽ có độ cao là 0. Nhiệm vụ của bạn là hã xác định chiều
cao của mọi nốt trong cây. 

*/

// Độ cao của con = Độ cao của bố + 1
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
bool visited[1005];
int height[1005];

void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            height[v] = height[u] + 1;
            DFS(v);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    height[1] = 0;
    DFS(1);
    for (int i = 1; i <= n; i++) {
        cout << height[i] << ' ';
    }
    return 0;
}