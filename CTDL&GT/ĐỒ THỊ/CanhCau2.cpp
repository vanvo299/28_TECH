// Ứng dụng của DFS, BFS : cạnh cầu 
/*
- Để xóa cạnh cầu thì tương đương với việc không xét đến nó, đánh dấu cạnh cần xóa và không duyệt 
vào cạnh này trong thuật toán DFS, BFS

*/
#include <bits/stdc++.h>
using namespace std;

int n, m; // Đỉnh, cạnh
bool visited[1005];
vector<int> adj[1005];
vector<pair<int, int>> dsCanh;

// DFS
void DFS(int u, int s, int t)
{
    visited[u] = true;
    // duyet danh sach ke cua dinh u
    for (int v : adj[u]) {
        // Nếu xét phải cạnh muốn loại bỏ thì không xét
        if ((u == s && v == t) || (u == t && v == s)) {
            continue;
        }
        if (!visited[v]) {
            DFS(v, s, t);
        }
    }
}

// Đếm số lượng thành phần liên thông
int TPLT(int s, int t)
{
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ++count;
            DFS(i, s, t);
        }
    }
    return count;
}

void canhCau2()
{
    int cc = TPLT(0, 0);
    int dem = 0;
    for (auto it : dsCanh) {
        int x = it.first, y = it.second;
        memset(visited, false, sizeof(visited));
        if (cc < TPLT(x, y)) {
            ++dem; // đếm có bao nhiêu cạnh cầu
            cout << "(" << x << ", " << y << ')' << ' '; // in ra các cạnh cầu
        }
    }
    cout << endl << dem << endl;
}

int main()
{
    cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        dsCanh.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    canhCau2();

    return 0;
}