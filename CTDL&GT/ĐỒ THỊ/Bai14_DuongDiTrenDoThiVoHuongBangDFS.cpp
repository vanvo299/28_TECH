/*
[Graph]. Bài 14. Đường đi trên đồ thị vô hướng bằng DFS

ĐỀ: Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy tìm đường
đi theo thuật toán DFS từ đỉnh s tới đỉnh t. Trong quá trình mở rộng của thuật toán DFS
luồn ưu tiên mở rộng đỉnh có số thứ tự nhỏ hơn 

-Input: Dòng đầu tiên là 4 số n, m, s, t tương ứng với số lượng đỉnh, cạnh của đồ thị, đỉnh bắt đầu
và đỉnh kết thúc. Các đỉnh của đồ thị được đánh số 1 tới n, m dòng tiếp theo mỗi dòng 
chứa đỉnh u, v (u != v) tương ứng với 1 cạnh của đồ thị

-Output: In ra đường đi từ s tới t nếu có đường đi, trường hợp không tồn tại đường đi thì in ra -1

*/
#include <bits/stdc++.h>
using namespace std;

int n, m, s, t; // số đỉnh, số cạnh, đỉnh bắt đầu, đỉnh kết thúc
vector<int> adj[1005];
bool visited[1005];
int parent[1005]; // parent[u] : là đỉnh cha của đỉnh u

// DFS
void DFS(int u)
{
    visited[u] = true;
    // duyet danh sach ke cua dinh u
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            DFS(v);
        }
    }
}

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
        
        // duyệt ds kề của đỉnh v mà chưa được thăm và đẩy vào hàng đợi
        for (int x : adj[v]) {
            if (!visited[x]) { // nếu x chưa được thăm
                q.push(x);
                visited[x] = true;
                parent[x] = v;
            }
        }
   }
}

int main()
{
    cin >> n >> m >> s >> t;
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    //DFS(s); 
    BFS(s);
    if (visited[t]) {
        vector<int> res;
        while(t != s) {
            // truy vết đường đi
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);

        // in nguoc lai vector
        reverse(res.begin(), res.end());
        for (int v : res) {
            cout << v << ' ';
        }
    }
    else cout << -1 << endl;
    return 0;
}