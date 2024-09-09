// SẮP XẾP TOPO
/*
Sắp xếp TOPO áp dụng cho đồ thị có hướng không có chu trình (DAG - Directed Acyclic Graph) là một
thứ tự của các đỉnh sao cho với mọi cạnh u -> v thì u sẽ xuất hiện trước v trong thứ tự TOPO. Một đồ thị
có thể tồn tại nhiều thứ tự TOPO khác nhau

*/

// Theo thứ tự duyệt xong 
#include <bits/stdc++.h>
using namespace std;

int n, m; // Đỉnh, cạnh
bool visited[1005];
vector<int> adj[1005];
stack<int> st;

void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
    st.push(u); // đỉnh sau khi đã duyệt xong => Thêm vào stack
}
int main()
{
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    DFS(1);
    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}