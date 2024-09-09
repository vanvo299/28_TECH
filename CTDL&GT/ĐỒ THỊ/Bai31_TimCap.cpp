/*
[GRAPH]. Bài 31. Tìm cặp

ĐỀ: Bạn được cung cấp một cây gốc với các nút và nút 1 là gốc. Có một đường đi duy nhất giữa hai nút bất kỳ. Ở
dây, d(i, j) được định nghĩa là số cạnh trong một đường đi ngắn nhất giữa 2 nút i và j. Nhiệm vụ của bạn phải
tìm số lượng cặp i, j sao cho d(i, j) = d(1, i) - d(1, j)
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
bool visited[1005];
int res = 0; 
int DFS(int u)
{
    visited[u] = true;
    int cnt = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            cnt += DFS(v); // Tổng số lượng con cháu của 1 đỉnh
        }
    }
    // cout << u << " " << res << endl;
    res += cnt;
    return cnt;
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
    DFS(1);
    cout << res << endl;
    return 0;
}