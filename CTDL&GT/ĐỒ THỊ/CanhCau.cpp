// Ứng dụng DFS, BFS : Cạnh cầu
/*
- Cạnh cầu : Những cạnh khi loại bỏ nó (chi loại bỏ cạnh, không loại bỏ 2 đỉnh) làm
tăng số thành phần liên thông của đồ thị
- Để kiểm tra cạnh cầu bằng thuật toán DFS hoặc BFS cần độ phức tạp là
O(E * (E + V)) bạn cần gọi E (duyệt E cạnh) lần thuật toán DFS hoặc BFS.

*/

/*
Đối với khi xét cạnh cầu, việc loại bỏ cạnh ra khỏi đò thị sẽ phức tạp hơn, bạn có thể sử dụng danh 
sách kề là set để có thể xóa nhanh hơn thay vì dùng vector
*/
#include <bits/stdc++.h>
using namespace std;
int n, m; // Đỉnh, cạnh
bool visited[1005];
vector<pair<int, int>> dsCanh;
set<int> adj[1005];

void DFS(int u)
{
    visited[u] = true;
    // duyet danh sach ke cua dinh u
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}
// đếm số lượng thành phần liên thông
int TPLT()
{
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ++count;
            DFS(i);
        }
    }
    return count;
}
int main()
{
    cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        dsCanh.push_back({u, v});
        adj[u].insert(v);
        adj[v].insert(u);
    }

    // đếm số lượng TPLT ban đầu
    int cc = TPLT();
    int dem = 0;
    for (auto it : dsCanh) {
        int x = it.first, y = it.second;
        // tạm thời xóa cạnh (x, y) ra khỏi đồ thị
        adj[x].erase(y);
        adj[y].erase(x);
        memset(visited, false, sizeof(visited));
        if (cc < TPLT()) {
            ++dem; // đếm có bao nhiêu cạnh cầu
            cout << "(" << x << ", " << y << ')' << ' '; // in ra các cạnh cầu
        }
        // thêm lại cạnh (x, y) vào đồ thị sau khi xét
        adj[x].insert(y);
        adj[y].insert(x);
    }
    cout << endl << dem << endl;
    return 0;
}