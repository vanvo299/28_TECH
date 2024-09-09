/*
[GRAPH]. Bài 41. Sửa đường

ĐỀ: Ở 28TechLand có n thành phố và m đường giữa chúng. Thật không may, tình trạng của 
những con đường quá kém nên chúng không thể được sử dụng. Nhiệm vụ của bạn là sửa
chữa một số con đường để có một con đường tốt giữa hai thành phố bất kỳ. Đối với mỗi 
con đường, bạn biết chi phí sửa chữa của nó và bạn nên tìm giải pháp sao cho tổng chi phí 
càng nhỏ càng tốt.

*/
#include <bits/stdc++.h>
using namespace std;

struct edge {
    int x, y, w; 
    // Đình đầu, đỉnh cuối, trọng số
};

int n, m;
vector<edge> dscanh;
int parent[10005], size[10005];

void ktao()
{
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        edge e{x, y, w};
        dscanh.push_back(e);
    }
}

int Find(int u)
{
    if (u == parent[u]) return u;
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
        size[v] += size[u];
    }
    else {
        parent[u] = v;
        size[u] += size[v];
    }
    return true;
}

void Kruskal()
{
    // Sắp xếp các cạnh theo trọng số
    sort(dscanh.begin(), dscanh.end(), [](edge a, edge b)->bool {
        return a.w < b.w;
    });

    long long d = 0; // Tổng trọng số của cây khung
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
    nhap();
    ktao();
    Kruskal();
    return 0;
}