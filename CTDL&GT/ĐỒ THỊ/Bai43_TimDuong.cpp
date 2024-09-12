/*
[GRAPH]. Bài 43. Tìm đường

ĐỀ: Cho một bảng S[][] kích thước NxM, bao gồm các ô trống, các vật cản. Ban đầu bạn ở vị trí
S. Nhiệm vụ của bạn là hãy di chuyển tới vị trí T, sao cho số lần đổi hướng không quá hai 
lần. Các bạn có thể di chuyển từ 1 ô sang 4 ô chung cạnh với ô hiện tại và không có vật
cản.

Input Format: Dòng 1 bắt đầu bởi hai số nguyên N và M. N dòng tiếp theo, mỗi dòng gồm M kí tự mô tả
bảng S. Trong đó: '.' là một ô trống, '*' là vật cản, 'S' là vị trí xuất phát và 'T' là vị trí đích.
(Chỉ có 1 vị trí S và T duy nhât).
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, s1, s2, t1, t2;
char a[505][505];
int ok = 0;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void Nhap()
{
    cin >> n >> m; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                s1 = i; s2 = j;
            }
            else if (a[i][j] == 'T') {
                t1 = i; t2 = j;
            }
        }
    }
}

void quayLui(int i, int j, int k_prev, int cnt)
{
    if (cnt > 3) return;
    if (i == t1 && j == t2) {
        ok = 1;
        return;
    }
    
    a[i][j] = '*';
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != '*') {
           if (k_prev == k)
                // Nếu vẫn đi cùng một hướng thì không tăng số lần đổi hướng
                quayLui(i1, j1, k, cnt);
            else 
                quayLui(i1, j1, k, cnt + 1);
            if (ok) return;
        }
    }
    a[i][j] = '.';
}
int main()
{
    Nhap();
    quayLui(s1, s2, -1, 0);
    if (ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}