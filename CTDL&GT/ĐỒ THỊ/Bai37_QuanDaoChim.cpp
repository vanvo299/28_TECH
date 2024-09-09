/*
[GRAPH]. Bài 37. Quần đảo chìm

ĐỀ: Thành phố Vice được xây dựng trên một nhóm các hòn đảo, với những cây cầu nối giữa
chúng. Như bất kỳ ai ở Vice City đều biết, nỗi sợ hãi lớn nhất của các thành phố là một 
ngày nào đó các hòn đảo sẽ bị nhấn chìm. Vấn đề lớn của việc này là một khi các hòn đảo
bị nhấn chìm, một số hòn đảo khác có thể bị ngắt kết nối. Bạn đã được thị trưởng thành
phố Vice thuê để nói cho ông ta biết có bao nhiêu hòn đảo, khi bị nhấn chìm, sẽ ngắt kết 
nối các bộ phận của thành phố Vice. Bạn nên biết rằng ban đầu tất cả các hòn đảo của 
thành phố đều được kết nối với nhau

Ouput: In ra số lượng hòn đảo khi bị ngập sẽ làm thành phố Vice bị ngắt kết nối

*/

// Tìm đỉnh trụ
#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
vector<int> adj[1005];
bool visited[1005];

void DFS(int u)
{
    cnt++;
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
    int res = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        cnt = 0;
        if (i == 1) DFS(2);
        else DFS(1);
        if (cnt != n - 1) res++;
    }
    cout << res << endl;
    return 0;
}