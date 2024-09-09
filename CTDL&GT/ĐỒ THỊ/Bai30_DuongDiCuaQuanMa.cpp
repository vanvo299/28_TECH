/*
[GRAPH]. Bài 30. Đường đi của quân Mã

ĐỀ: Cho bàn cờ cỡ nxn, một con mã ở ô (s, t) muốn di chuyển sang ô (u, v). Hãy tìm số bước 
tối thiểu để con mã có thể đến ô (u, v) hoặc xác định rằng không thể đi tới ô (u, v), bàn
cờ A được mô tả bằng các giá trị 0, 1, trong đó giá trị 1 thì con mã có thể tự do di chuyển
đến ô này, ngược lại nếu giá trị tại một ô của bàn cờ là 0 thì ccon mã không thể 
di chuyên đến ô này

*/
#include <bits/stdc++.h>
using namespace std;

int n, s1, s2, t1, t2;
int a[1005][1005];

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2}; 
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int BFS()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{s1, s2}, 0});
    a[s1][s2] = 0;
    while(!q.empty()) {
        auto it = q.front(); q.pop();
        int i = it.first.first, j = it.first.second, d = it.second;
        if (i == t1 && j == t2) return d;
        for(int k = 0; k < 8; k++) {
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
    cin >> n >> s1 >> s2 >> t1 >> t2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cout << BFS();
    return 0;
}