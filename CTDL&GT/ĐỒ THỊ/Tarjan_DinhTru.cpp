/*
[GRAPH]. Thuật toán Tarjan - ĐỈNH TRỤ

- Ý tưởng: Cho đồ thị G vô hướng, trên đồ thị có 2 đỉnh U và đỉnh V, giữa U và V đang có đường đi từ U tới
V theo thứ tự duyệt DFS, nếu ta có thể từ V đi tới tổ tiên A của U mà khồng cần thông qua U điều
đó chứng tỏ đồ thị có cạnh ngược và việc loại bỏ U khỏi đồ thị không làm tăng số thành phần
liên thông của đồ thị, khi đó U không phải là đỉnh trụ (Articulation Point)

- Có hai trường hợp để U là đỉnh trụ trên đồ thị
+ Tất cả đường đi từ A tới V đều phải đi qua U
+ U là gốc của cây DFS với ít nhất 2 node con

=> Vì thế điều kiẹn để đỉnh U là đỉnh trụ là: disc[u] <= low[v]. Trong đó disc[u] < low[v] thể hiện rằng từ v
không thể tìm được đường đi nào khác tới tổ tiên của u mà không thông qua u. disc[u] = low[v] trong
trường hợp u là gốc của chu trình chứa v.

*/
#include <bits/stdc++.h>
using namespace std;

int n, m, timer = 0;
vector<int> adj[1005];
int disc[1005], low[1005];
bool visited[1005], AP[1005]; // Articulation point

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
    memset(visited, false, sizeof(AP));
}

void DFS(int u, int parent)
{
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int child = 0; // số lượng con của một đỉnh
    for (int v : adj[u]) {
        if (v == parent) continue;
        if (!visited[v]) {
            DFS(v, u);
            ++child;
            low[u] = min(low[u], low[v]);
            if (parent != -1 && disc[u] <= low[v]) {
                AP[u] = true;
            }
        }
        else {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (parent == -1 && child > 1) AP[u] = true;
}
int main()
{
    nhap();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (AP[i]) cout << i << ' ';
    } 
    return 0;
}
