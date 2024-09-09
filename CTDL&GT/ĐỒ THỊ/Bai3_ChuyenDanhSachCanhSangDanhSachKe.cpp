/*
[Graph]. Bài 3. Chuyển danh sách cạnh sang danh sách kề (có hướng)

Đề: Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy chuyển đổi đồ thị
dưới dạng danh sách cạnh này sang danh sách kề tương ứng.

- Input: Dòng đầu tien là 2 số n và m, tương ứng với số lượng đỉnh và cạnh của đồ thị. Các đỉnh
của đồ thị được đánh số từ 1 tới n. M dòng tiếp theo mỗi dòng chứa đỉnh u, v tương ứng với một cạnh của đồ thị

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

int main()
{
    int n, m; cin >>n >> m; // Đỉnh, cạnh
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    
    for (int i = 1; i <=n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int v : adj[i]) {
            cout << v << ' ';
        }
        cout << endl;
    }
    return 0;
}