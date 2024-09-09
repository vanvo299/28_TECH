/*
[GRAPH]. Bài 25. Đếm số phòng

ĐỀ:  Bạn được đưa cho một bản đồ của một tòa nhà và nhiệm vụ của bạn là đếm số lượng
phòng của tòa nhà đó. Kích thước của bản đồ là n x m hình vuông và mỗi hình vuông là
sàn hoặc tường. Bạn có thể đi sang trái, phải và xuống qua các ô sàn

-Input: Dòng nhập đầu tiên có hai số nguyên n và m: chiều cao và chiều rộng của bản đồ. Khi đó
có n dòng gồm m ký tự mô tả bản đồ. Mỗi kí tự là một trong hai kí tự '.' hoặc '#' tương
ứng với sàn nhà và tường.

*/

// ĐẾM số thành phần liền thông, mỗi thành phần liên thông tương ứng với 1 phòng
#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1005][1005];
int cnt = 0;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void DFS(int i, int j)
{
    for (int k = 0; k < 4; k++) {
        a[i][j] = '#';
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == '.') {
            DFS(i1, j1);
        }
    }
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
                cnt++;
                DFS(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}