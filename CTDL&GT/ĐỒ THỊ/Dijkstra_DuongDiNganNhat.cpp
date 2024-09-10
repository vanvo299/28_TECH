/*
[GRAPH]. Thuật toán Dijkstra - Tìm đường đi ngắn nhất

- Thuật toán Dijkstra được sử dụng để tìm đường đi ngắn nhất từ 1 đỉnh tới 
mọi đỉnh còn lại trên đồ thị, có thể áp dụng cho cả đồ thị có hướng và vô
hướng không chứa trọng số âm. Độ phức tạp: O((E + V)logV)

- Hướng dẫn cài đặt:
+ Ta sử dụng hàng đợi ưu tiên Q lưu pair với first lưu khoảng cách
đường đi ngắn nhất từ đỉnh nguồn, và second lưu đỉnh. Q sẽ sắp xếp
các phần tử theo khoảng cách đường đi tăng dần, nếu 2 đỉnh có cùng 
khoảng cách đường đi thì sắp xếp theo số thứ tự đỉnh tăng dần.
+ Ban đầu Q chỉ bao gồm cặp {0, s} với s là đỉnh bắt đầu của thuật 
toán. Thuật toán sẽ được lặp lại khi Q còn chưa rỗng, mỗi lần lặp 
sẽ lấy ra cặp (d, u) ở đỉnh hàng đợi Q tương ứng với đỉnh u là 
đỉnh có đường đi ngắn nhất tính từ đỉnh nguồn s. Nếu d > dist[u]
với dist[u] là khoảng cách đường đi ngắn nhất ghi nhận được cho 
đỉnh u thì ta sẽ bỏ qua u
+ Khi đỉnh u được xét nó sẽ cố gắng cập nhật khoảng cách ngắn nhất
cho các đỉnh v kề với u, sau đó tiếp tục đẩy đỉnh v và dist[v] vào hàng
đợi, điều này có thể dẫn tới nhiều phiên bản khác nhau của cùng 1 
đỉnh với khoảng cách khác nhau trong hàng đợi. Tuy nhiên ta sẽ luôn 
chọn phiên bản có khoảng cách ngắn nhất để xét trước
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, s; // Đỉnh, cạnh, đỉnh nguồn
vector<pair<int, int>> adj[1005];

void nhap()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void Dijkstra(int s)
{
    vector<int> d(n + 1, 1e9); // Mảng lưu chi phí đường đi từ đỉnh nguồn
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    while(!Q.empty()) {
        // Chọn ra đỉnh u có đường đi ngắn nhất => relaxation
        pair<int, int> top = Q.top(); Q.pop();
        int u = top.second, kc = top.first;
        if (kc > d[u]) continue;
        // relax
        for (auto it : adj[u]) {
            int v = it.first, w = it.second;
            if (d[v] > d[u] + w) {
                // cap nhat
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << d[i] << ' ';
    }
}
int main()
{
    nhap();
    Dijkstra(1);
    return 0;
}