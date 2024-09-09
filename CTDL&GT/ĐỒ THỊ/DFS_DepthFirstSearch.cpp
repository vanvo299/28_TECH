/*
Thuật toán DFS - Depth First Search
- Thuật toán tìm kiếm theo chiều sâu là một giải thuật tìm kiếm, duyệt đồ thị
sử dụng đệ quy. Thuật toán ưu tiên đi sâu nhất có thể, ở đây ta thống nhất
khi mở rộng đồ thị thì sẽ ưu tiên mở rộng đỉnh có số thứ tự nhỏ hơn trước.

*/

/*
- DFS :
    => Kiểm tra đồ thị vô hướng liên thông <=> chỉ có 1 thành phần liên thông
    => Đếm số lượng thành phần liên thông
    => Có đường đi giữa hai đỉnh hay không
    => Truy vết đường đi 
*/
#include <bits/stdc++.h>
using namespace std;

int n, m; // đỉnh, cạnh
vector<int> ke[1005];
bool visited[1005];
int a[1005][1005];
vector<pair<int, int>> dsCanh;

// DFS, khi đồ thị được lưu dưới dạng ds kề 
void DFS1(int u)
{
    cout << u << ' ';
    visited[u] = true;
    // duyet danh sach ke cua dinh u
    for (int v : ke[u]) {
        if (!visited[v]) {
            DFS1(v);
        }
    }
}

// DFS, khi đồ thị được lưu dưới dạng ma trận kề
void DFS2(int u)
{
    cout << u << ' ';
    visited[u] = true;
    // duyet ds ke cua dinh u : duyet dong thu u trong ma tran ke a
    for (int i = 1; i <= n; i++) {
        if (a[u][i] == 1) {
            if (!visited[i]) {
                DFS2(i);
            }
        }
    }
}

// DFS, Khi đồ thị được lưu dưới dạng danh sách cạnh
void DFS3(int u)
{
    cout << u << ' ';
    visited[u] = true;
    // duyet ds ke cua dinh u :
    for (auto it : dsCanh) {
        if (it.first == u) {
            if (!visited[it.second]) {
                DFS3(it.second);
            }
        }
        if (it.second == u) {
            if (!visited[it.first]) {
                DFS3(it.first);
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
        ke[u].push_back(v);
        ke[v].push_back(u);
    }

    DFS1(1);


    return 0;
}