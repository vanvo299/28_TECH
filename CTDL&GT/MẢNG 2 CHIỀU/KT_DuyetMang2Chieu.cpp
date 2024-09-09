/*
5. Kĩ thuật duyệt ô chung đỉnh với ô [i][j]
*/

#include <bits/stdc++.h>
using namespace std;

// duyệt 8 ô xung quanh
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// duyệt 4 ô xung quanh
// int dx[4] = {-1, 0, 0, 1};
// int dy[4] = {0, -1, 1, 0};

// duyệt đường đi của quân mã trong cờ vua
// int dx[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
// int dy[8] = {-1, +1, -2, +2, -2, +2, -1, +1};
int main()
{
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int i = 1, j = 1;
    for (int k = 0; k < 8; k++) {
        int i1 = i + dx[k], j1 = j + dy[k];
        if ((i1 >= 0 && i1 <= 3) && (j1 >= 0 && j1 <= 3)) {
        cout << a[i1][j1] << " ";
        }
    }
    return 0;
}