// SẮP XẾP TOPO
// Có thể dùng TOPO sort để kiểm tra chu trình trong đồ thị có hướng
/*
- Sắp xếp TOPO áp dụng cho đồ thị có hướng không có chu trình (DAG - Directed Acyclic Graph) là một
thứ tự của các đỉnh sao cho với mọi cạnh u -> v thì u sẽ xuất hiện trước v trong thứ tự TOPO. Một đồ thị
có thể tồn tại nhiều thứ tự TOPO khác nhau

- Sắp xếp TOPO với BFS hay thuật toán Kahn, thuật toán xóa dần đỉnh
+ Bước 1: Tính bán bậc vào của mọi đỉnh trên đồ thị
+ Bước 2: Đưa các đỉnh có bán bậc vào bằng 0 vào hàng đợi
+ Bước 3: Duyệt và xóa đỉnh khỏi đầu hàng đợi, duyệt các đỉnh kề với đỉnh này và giảm bán bậc vào của 
các đỉnh kề, nếu đỉnh nào sau khi giảm có bán bậc vào bằng 0 thì tiếp tục đẩy vào hàng đợi
+ Bước 4: Lặp lại bước 3 cho tới khi hàng đợi còn phần tử
+ Bước 5: Nếu số lượng đỉnh được duyệt bằng với số đỉnh của đồ thị 
thì đó chính là thứ tự topo, ngược lại ta có thẻ suy ra đồ thị tồn tại chu trình

*/
#include <bits/stdc++.h>
using namespace std;

int n, m; // Đỉnh, cạnh
vector<int> adj[1005];
int degree[1005]; // bán bậc vào

void Kahn()
{
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            degree[v]--;
            if (degree[v] == 0) q.push(v);
        }
    }
    if (topo.size() < n) cout << "Do thi co chu trinh\n";
    else {
        for (int i : topo) {
            cout << i << ' ';
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
        degree[v]++;
    }
    Kahn();
    return 0;
}