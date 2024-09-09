// Ứng dụng DFS, BFS : Đỉnh trụ
/*
- Đỉnh trụ: là đỉnh khi loại bỏ đỉnh này và các cạnh liên thuộc với đỉnh này sẽ làm tắng
số thành phần liên thông của đồ thị
- Để kiểm tra đỉnh trụ bằng thuật toán DFS hoặc BFS cần độ phức tạp là O(V * (E + V)), 
bạn cần gọi V (duyệt V đỉnh) lần thuật toán DFS hoặc BFS

*/
#include <bits/stdc++.h>
using namespace std;

int n, m; // đỉnh, cạnh
vector<int> adj[1005];
bool visited[1005];

void DFS(int u)
{
    visited[u] = true;
    // duyet ds ke cua dinh u
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

// Đếm số lượng thành phần liên thông ban đầu của đồ thị
int TPLT()
{
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ++count;
            DFS(i); // BFS(i)
        }
    }
    return count;
}

void dinhTru()
{
    int cc = TPLT(); // Số thành phần liên thông ban đầu
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true; // loại bỏ i ra khỏi đồ thị
        if (cc < TPLT()) {
            // nếu số TPLT sau khi đánh dấu đỉnh i lớn hơn số TPLT ban đầu thì inn ra đỉnh i
            cout << i << ' ';
        }
    }
}
int main()
{
    cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Dinh la dinh tru la: ";
    dinhTru();
    return 0;
}