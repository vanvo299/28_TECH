/*
[GRAPH]. Bài 42. Lát đường

ĐỀ: Ở 28TechLand có n thành phố và ban đầu không có đường giữa chúng. Tuy nhiên, mỗi ngày
một con đường mới sẽ được xây dựng và sẽ có tổng cộng m con đường. Một cụm thành
phố là một nhóm các thành phố trong đố có một tuyến đường giữa hai thành phố bất kỳ
bằng cách sử dụng các con đường. Sau mỗi ngày, nhiệm vụ của bạn là tìm ra số lượng cụm 
thành phố và kích thước của cụm thành phố lớn nhất

*/
#include <bits/stdc++.h>
using namespace std;

int n, m, parent[1005], size[1005];
int size_max = 1;

void ktao()
{
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int Find(int u)
{
    if (u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y) return false;
    if (size[x] > size[y]) {
        parent[y] = x;
        size[x] += size[y];
    }
    else {
        parent[x] = y;
        size[y] += size[x];
    }
    size_max = max({size_max, size[x], size[y]});
}
int main()
{
    cin >> n >> m;
    ktao();
    vector<pair<int, int>> vt;
    int soLuongTPLT = n;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if (Union(u, v)) {
            soLuongTPLT--;
        }
        vt.push_back({soLuongTPLT, size_max});
        // cout << soLuongTPLT << " " << size_max << endl; 
    }
    cout << endl;
    for (auto it : vt) {
        cout << it.first << ' ' << it.second << endl;
    }
    return 0;
}