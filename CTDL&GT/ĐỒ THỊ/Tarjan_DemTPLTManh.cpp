// [GRAPH]. Thuật toán Tanjan - Đếm thành phần liên thông mạnh
#include <bits/stdc++.h>
using namespace std;

int n, m; // Đỉnh, cạnh
vector<int> adj[1005];
bool visited[1005], in_stack[1005];
int timer = 0, scc = 0;
int disc[1005], low[1005];
stack<int> st;

void nhap()
{
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    memset(visited, false, sizeof(visited));
    memset(in_stack, false, sizeof(in_stack));
}

void DFS(int u)
{
    visited[u] = true; in_stack[u] = true;
    disc[u] = low[u] = ++timer;
    st.push(u);
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
    if (low[u] == disc[u]) {
        ++scc;
        while(st.top() != u) {
            cout << st.top() << ' ';
            in_stack[st.top()] = false;
            st.pop();
        } 
        cout << st.top() << endl;
        in_stack[st.top()] = false;
        st.pop();
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
    cout << endl << scc << endl;
    return 0;
}