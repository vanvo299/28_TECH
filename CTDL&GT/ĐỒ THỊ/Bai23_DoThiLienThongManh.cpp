/*
[GRAPH]. Bài 23. Đồ thị liên thông mạnh

ĐỀ: Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra đồ thị có liên thông
mạnh hay không ? Bài này các bạn thử cài đặt bằng 3 cách là: brute force, thuật toán Tarjan, thuật toán
Kosaraju.

- In ra 1 nếu đồ thị là liên thông mạnh, ngược lại in ra 0
*/ 
#include <bits/stdc++.h>
using namespace std;

int n, m; /// Đỉnh, cạnh
bool visited[1005];
vector<int> adj[1005];
int cnt = 0; // biến đếm xem từ 1 đỉnh có thể loan được tới bao nhiêu điểm

void DFS(int u) 
{
    cnt++;
    visited[u] = true;
    // duyet ds ke cua dinh u
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int check()
{
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        memset(visited, false, sizeof(visited));
        DFS(i);
        if (cnt != n) return 0;
    }
    return 1;
}
int main()
{

    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    if (check()) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}