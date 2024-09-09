/*
[GRAPH]. Thuật toán Tarjan
- Tarjan là một thuật toán giúp liệt kê, đếm thành phần liên thông của đồ thị
với độ phức tạp là O(V + E), Tarjan chỉ cần 1 lần duyệt DFS là có thể liệt kê 
được SCC thay vì 2 lần như Kosaraju
- Để hiểu được thuật toán Tarjan trước hết cần hiểu được ý nghĩa của 2
mảng là disc[] và low[] được tính toán dựa trên thứ tự duyệt các đỉnh trên
đồ thị bằng thuật toán DFS
- Ý nghĩa của 2 mảng disc[] và low[]:
+ Mảng disc[u]: Chỉ ra thời gian bắt đầu thăm đỉnh u theo thuật toán DFS
+ Mảng low[u]: Chỉ ra thời gian thăm sớm nhất của một đỉnh có thể đi tới được từ một cây con có gốc là u

- Thuật toán Tarjan dựa trên quan sát, những đỉnh u thỏa mãn disc[u] = low[u]
sẽ là đỉnh bắt đầu của một thành phần liên thông mạnh
*/
#include <bits/stdc++.h>
using namespace std;

int n, m; // Đỉnh, cạnh
vector<int> adj[1005];
bool visited[1005];
int timer = 0;
int disc[1005], low[1005];

void nhap()
{
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u)
{
    disc[u] = low[u] = ++timer;
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            // v chưa được thăm
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            // v đã được thăm
            low[u] = min(low[u], disc[v]);
        }
    }
}
int main()
{
    nhap();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << disc[i] << ' ' << low[i] << endl;
    }
    return 0;
}