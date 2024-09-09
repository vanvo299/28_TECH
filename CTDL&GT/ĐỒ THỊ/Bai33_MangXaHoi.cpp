/*
[GRAPH]. Bài 33. Mạng xã hội (SPOJ)

ĐỀ: Tý đang xây dựng một mạng xã hội và mời các bạn của mình dùng thử. Bạn của bạn cũng
là bạn. Vì vậy, Tí muốn mạng xã hội vủa mình là hoàn hảo, tức với mọi bộ ba X, Y, Z nếu X
kết bạn với Y, Y kết bạn với Z thì X và Z cũng phải là bạn bè của nhau trên mạng xã hội. Các 
bạn hãy xác định xem mạng xã hội hiện tại của Tý có là hoàn hảo hay không ? Nếu có hãy
in ra "YES", "NO" trong trường hợp ngược lại.

** Ý tưởng: Cho n đỉnh, Chứng minh được đồ thị phải có C(2, n) cạnh => thì suy ra là hoàn hảo .
Vì C(2, n) là số cạnh max có thể tạo thành đồ thị từ n đỉnh
=> n đỉnh có C(2, n) => đồ thị hoàn hảo => MXH hoàn hảo
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
int dem = 0;
bool visited[1005];
vector<int> adj[1005];

void DFS(int u)
{
    dem++; // dem so dinh trong 1 TPLT
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int canhHoanHao = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dem = 0;
            DFS(i);
            canhHoanHao += (dem * (dem - 1)) / 2;
        }
    }
    if (m == canhHoanHao) 
        cout << "YES" << endl;
    else 
        cout << "NO";
    return 0;
}