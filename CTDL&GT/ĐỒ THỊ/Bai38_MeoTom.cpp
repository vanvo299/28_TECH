/*
[GRAPH]. Bài 38. Mèo Tom

ĐỀ: Chú mèo Tom đang ở gốc 1 cây với nhiều lá và cành. Cái cây này có rất nhiều lá và các đỉnh 
trung gian. Ở các nốt lá có treo các con cá và mèo Tom mong muốn ăn được nhiều cá nhất
có thể vì thế nó dự định sẽ trèo từ gốc cây tương ứng với đỉnh 1 và đi lần lượt tới các nốt lá
để ăn cá, nhưng trên đường đi từ nốt gốc lên nốt lá, mèo Tom phải đi qua các nốt trung 
gian. Các nốt trung gian này sẽ có những con gián và mèo Tom chỉ có thể đi đến các nốt lá
để ăn cá nếu trên đường đi từ nốt gốc tới nốt lá có không quá m con gián liên tiếp. Bạn 
hãy giúp mèo Tom đếm số cá tối đa mà nó có thể ăn được nhé.

-Input: Dòng đầu tiên là n và m, tương ứng với số lượng nốt của cây và số con gián liên tiếp. Dòng
thứ 2 gồm n số có giá trị 1 hoặc 0, tương ứng với vị trí ở nốt thứ i có hoặc không có con gián. 
N - 1 dòng tiếp theo mỗi dòng là mô tả 1 cạnh của cây

-Output: In ra số con cá tối đa mèo Tom có thể ăn được

*/
#include <bits/stdc++.h>
using namespace std;

int n, m, d[10005];
vector<int> adj[1005];
bool visited[1005];
int res = 0;

void DFS(int u, int lienTiep)
{
    visited[u] = true;
    int ok = 0;
    for (int v : adj[u]) {
        if (!visited[v]) {
            ok = 1;
            if (d[v] == 1 && lienTiep + 1 <= m) 
                DFS(v, lienTiep + 1);
            else if (d[v] == 0) 
                DFS(v, 0);
        }
    }
    if (!ok) res++;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, d[1]);
    cout << res << endl;
    return 0;
}
