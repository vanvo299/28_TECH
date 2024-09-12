/*
[GRAPH]. Bài 41. Sửa đường

ĐỀ: Ở 28TechLand có n thành phố và m đường giữa chúng. Thật không may, tình trạng của 
những con đường quá kém nên chúng không thể được sử dụng. Nhiệm vụ của bạn là sửa
chữa một số con đường để có một con đường tốt giữa hai thành phố bất kỳ. Đối với mỗi 
con đường, bạn biết chi phí sửa chữa của nó và bạn nên tìm giải pháp sao cho tổng chi phí 
càng nhỏ càng tốt.

*/

// Làm bằng thuật toán Kruskal - Tìm cây khung nhỏ nhất
#include <bits/stdc++.h>
using namespace std;

struct edge {
    int x, y, w; 
    // Đỉnh đầu, đỉnh cuối, trọng số
};
int n, m; // Đỉnh, cạnh
vector<edge> dscanh;
int size[10005], parent[10005];

void ktao()
{
    for (int i = 1; i <= n; i++) {
        size[i] = 1;
        parent[i] = i;
    }
}

int Find(int u)
{
    if (u = parent[u]) return u;
    else 
        return parent[u] = Find(parent[u]);
}

bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v) return false;

    if (size[u] > size[v]) {
        parent[v] = u;
        size[u] += size[v];
    }
    else {
        parent[u] = v; 
        size[v] += size[u];
    }
    return true;
}

void Nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        edge e{x, y, w};
        dscanh.push_back(e);
    }
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void Kruskal()
{
    sort(dscanh.begin(), dscanh.end(), cmp);

    int d = 0;
    vector<edge> MST;
    for (int i = 0; i < m; i++) {
        if (MST.size() == n - 1) break;
        edge e = dscanh[i];
        if (Union(e.x, e.y)) {
            MST.push_back(e);
            d += e.w;
        }
    }
    if (MST.size() < n - 1) cout << "IMPOSSIBLE\n";
    else cout << d << endl;
}
int main()
{
    Nhap();
    ktao();
    cout << endl;
    Kruskal();
    return 0;
}
