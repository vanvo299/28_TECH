/*
[GRAPH]. Thuật toán Kruskal - Tìm cây khung nhỏ nhất

- Tư tưởng của thuật toán Kruskal đó là ở mỗi bước bạn sẽ đưa thêm 1 cạnh có
trọng số nhỏ nhất (chưa thuộc cây khung) vào cây khung nếu nó không tạo chu 
trình. Để code được thuật toán Kruskal các bạn cần biết cấu trúc dữ liệu DSU
- Thuật toán sẽ kết thúc nếu tìm đủ N - 1 cạnh hoặc không còn cạnh nào chưa nằm
trong cây khung

*/
#include <bits/stdc++.h>
using namespace std;

struct edge {
    int x, y, w; 
    // Đỉnh đầu, đỉnh cuối, trọng số
};
int n, m; // Đỉnh, cạnh
vector<edge> dscanh; // Tập cạnh
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
        size[u] += size[v];
    }
    else {
        parent[u] = v;
        size[v] += size[u];
    }
    return true;
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

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
void Kruskal()
{
    // Bước 1: Sắp xếp ds cạnh theo trọng số tăng dần
    sort(dscanh.begin(), dscanh.end(), cmp);
    // Bước 2: Lặp
    int d = 0; // Tổng trọng số
    vector<edge> MST; // Lưu ds cạnh trong cây khung
    for (int i = 0; i < m; i++) {
        if (MST.size() == n - 1) break;
        edge e = dscanh[i];
        // MST + e => có tạo thành chu trình hay không
        if (Union(e.x, e.y)) {
            MST.push_back(e);
            d += e.w;
        }
    }
    // Kết quả
    if (MST.size() < n - 1) {
        cout << "Do Thi Lien Thong\n";
    }
    else {
        cout << d << endl; // Trọng số của cây khung cực tiểu
        // In ra các cạnh thuộc cây khung cực tiểu
        for (auto it : MST) {
            cout << it.x << ' ' << it.y << ' ' << it.w << endl;
        }
    }
}
int main()
{
    nhap();
    ktao();
    cout << endl;
    Kruskal();
    return 0;
}