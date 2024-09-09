/*
[GRAPH]. Bài 32. Diện tích

ĐỀ: Bạn được cung cấp một lưới 2D. Dấu '#' đại diện cho chướng ngại vật và dấu '.' đại diện
cho không gian trống. Bạn cần tìm các khu vực của các thành phần bị ngắt kết nối. Các ô 
(i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1) là các ô liền kề với ô (i, j)
*/

// Đếm số đỉnh trong thành phần liên thông
#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[1005][1005];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int DFS(int i, int j)
{
    a[i][j] = '#';
    int cnt = 1;
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == '.') {
            cnt += DFS(i1, j1);
        }
    } 
    return cnt;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.') {
                int res = DFS(i, j);
                cout << res << ' ';
            }
        }
    }
    return 0;
}