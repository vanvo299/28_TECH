/*
[GRAPH]. Bài 29. Đường đi trong mê cung

ĐỀ: Cho mê cung A có n hàng, n cột. Một con chuột xuất phát từ ô (s, t) và di chuyển tới ô (u, v). Nhiệm vụ của bạn
là xác định số bước đi tối thiểu để con chuột có thể di chuyển từ ô (s, t) tới ô (u, v) hoặc xác định rằng không
thể tìm được đường tới ô (u, v). Mê cung A chỉ bao gồm các số 1 hoặc 0. Trong đó 1 đại diện cho đường đi và 0
đại diện cho vật cản, con chuột chỉ có thể di chuyển từ ô hiện tại sang các ô chung đỉnh với nó và có đường đi

*/

#include <bits/stdc++.h>
using namespace std;
int n, s1, s2, t1, t2;
int a[1005][1005];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int BFS()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{s1, s2}, 0});
    a[s1][s2] = 0;
    while(!q.empty()) {
        auto it = q.front(); q.pop();
        int i = it.first.first, j = it.first.second, d = it.second;
        if (i == t1 && j == t2) return d;
        for (int k = 0; k < 8; k++) {
            int i1 = i + dx[k], j1 = j + dy[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1]) {
                q.push({{i1, j1}, d + 1});
                a[i1][j1] = 0;
            }
        }
    }
    return -1;
}
int main()
{
    cin >> n;
    cin >> s1 >> s2 >> t1 >> t2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cout << BFS() << endl;
    return 0;
}