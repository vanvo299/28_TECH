/*
[GRAPH]. BÀi 46. Di chuyển trên bảng số

ĐỀ: Cho một bảng số kích thước N x M. Chi phí khi đi qua ô (i, j). Nhiệm vụ của bạn là hãy tìm một
đường đi từ ô (1, 1) tới ô (N, M) sao cho chi phí là nhỏ nhất. Tại mỗi ô, bạn được phép đi sang trái, sang phải, đi
lên trên và xuống dưới
*/
#include <bits/stdc++.h>
using namespace std;

#define pip pair<int, pair<int, int>>
int n, m, a[505][505], d[505][505];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void Dijkstra()
{
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            d[i][j] = 1e9;

    d[1][1] = a[1][1];
    priority_queue<pip, vector<pip>, greater<pip>> Q;
    Q.push({0, {1, 1}});
    while(!Q.empty()) {
        auto top = Q.top(); Q.pop();
        int i = top.second.first, j = top.second.second;
        int khoangCach = top.first;
        if (khoangCach > d[i][j]) continue;
        //relax
        for (int k = 0; k < 4; k++) {
            int i1 = i + dx[k], j1 = j + dy[k];
            if (d[i1][j1] > d[i][j] + a[i1][j1]) {
                d[i1][j1] = d[i][j] + a[i1][j1];
                Q.push({d[i1][j1], {i1, j1}});
            }
        }
    }
    cout << d[n][m];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    Dijkstra();
    return 0;
}