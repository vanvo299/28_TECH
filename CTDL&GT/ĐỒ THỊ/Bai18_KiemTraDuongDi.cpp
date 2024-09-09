/*
[Graph]. Bài 18. Kiểm tra đường đi

ĐỀ: Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Có Q truy vấn,
mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh s và t có tồn tại đường đi tới nhau hay không ?

- Output: Đối với mỗi truy vấn in ra 1 nếu có đường đi giữa s và t, ngược lại in ra -1
*/

#include <bits/stdc++.h>
using namespace std;

int n, m; // Số đỉnh, Số cạnh, Đỉnh bắt đầu, Đỉnh kết thúc
vector<int> adj[1005];
bool visited[1005];
int TPLT[1005];
int cnt = 0;

void DFS(int u)
{
    visited[u] = true;
    TPLT[u] = cnt; // đánh dấu đỉnh u thuộc thành phần liên thông thứ mấy
    // duyet danh sach ke cua dinh u
    for (int v : adj[u]) {
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            DFS(i); // BFS(i) : Dùng thuật toán BFS cũng được
        }
    }
    
    int q; cin >> q;
    while(q--) {
        int u, v; cin >> u >> v;
        if (TPLT[u] == TPLT[v]) cout << "YES\n";
        // 2 đỉnh mà có đường đi thì chúng có cùng thành phần liên thông
        else cout << "NO\n";
    }
    return 0;
}