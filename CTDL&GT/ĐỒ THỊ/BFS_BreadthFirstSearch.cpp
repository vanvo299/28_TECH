/*
Thuật toán BFS - Breadth First Search
- Thuật toán tìm kiém theo chiều rộng ưu tiên mở rộng các đỉnh gần đỉnh 
nguông hơn. Trên đồ thị không có trọng số thì thuật toán BFS cho đường đi
ngắn nhất giữa 2 đỉnh

*/
#include <bits/stdc++.h>
using namespace std;

int n, m; // đỉnh, cạnh
vector<int> adj[1005];
bool visited[1005];

// BFS
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    // STEP 2: Lặp khi mà hàng đợi vẫn còn phần tử
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << ' ';
        // duyệt ds kề của đỉnh v mà chưa được thăm và đẩy vào hàng đợi
        for (int x : adj[v]) {
            if (!visited[x]) { // nếu x chưa được thăm
                q.push(x);
                visited[x] = true;
            }
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

    BFS(1);
    return 0;
}