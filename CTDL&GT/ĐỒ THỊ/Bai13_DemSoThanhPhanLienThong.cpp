/*
[Graph]. Bài 13. Đếm số thành phần liên thông

Đề: Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy đếm số thành phần liên thông
của đồ thị

*/
#include <bits/stdc++.h>
using namespace std;

int n, m; // đỉnh, cạnh
bool visited[1005];
vector<int> ke[1005];

void DFS(int u)
{
    visited[u] = true;
    // duyet ds ke cua dinh u
    for (int v : ke[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}
int main()
{
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }

    int dem = 0; // đếm số lượng thành phần liên thông
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i);
            ++dem;
        }
    }
    cout << dem << endl;
    return 0;
}
