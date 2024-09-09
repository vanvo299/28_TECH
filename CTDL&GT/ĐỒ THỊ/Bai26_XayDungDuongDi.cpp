/*
[GRAPH]. Bài 26. Xây dựng đường đi

ĐỀ: Japan has n cities, and m roads between them. The goal is to construct new
roads so that there is a route between any two cities
Your task is to find ou the minimum number of roads required, and also
determine which roads should be built.

DỊCH: Nhật Bản có n thành phố và m con đường giữa chúng. Mục tiêu là xây dựng thêm các con đường mới sao cho có một 
tuyến đường nối giữa bất kỳ hai thành phố nào. Nhiệm vụ của bạn là tìm ra số lượng 
tối thiểu các con đường cần xây dựng, và cũng xác định những con đường nào cần được xây dựng.

*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[1005];
vector<int> adj[1005];
int cnt = 0;

void DFS(int u)
{
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
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> v; // lưu các đỉnh xét đầu tiên ở mỗi thành phần liên thông
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            v.push_back(i);
            cnt++;
            DFS(i);
        }
    }
    cout << cnt - 1 << endl;
    for (int i = 1; i < v.size(); i++) {
        cout << v[i - 1] << ' ' << v[i];
    }
    return 0;
}