/*
[Mảng 2 chiều]. Bài 30. Đường đi của quân Xe

Đề: Tèo khá thích chơi cờ vua và quân cờ mà Tèo yêu thích đó là quân Xe, bây giờ Tèo có một bàn cờ N x N
trên bàn cờ sẽ có những ô trống và có những ô có vật cản, nhiệm vụ của bạn là hãy xác định xem số lượng ô 
trên bàn cờ mà quân Xe có thể di chuyển tới, biết rằng nó có thể đi qua đi lại 1 ô trống nhiều lần và không thể
đi vào ô có vật cản.

- Bàn cờ gồm N hàng N cột, mỗi ô là số 1 tương ứng với vật cản và ô số 0 tương ứng với ô trống. Ban đầu quân 
xe nằm ở vị trí hàng S và cột T và ô (S, T) là ô trống.
*/

#include <bits/stdc++.h>
using namespace std;
int n, s, t, dem = 0;
int a[100][100];

void nhap()
{
    cin >> n >> s >> t;
    --s; --t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

int dx[4] = {-1, 0, 0 , 1};
int dy[4] = {0, - 1, 1, 0};

void move(int i, int j)
{
    a[i][j] = 1;
    ++dem;
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && a[i1][j1] == 0) {
            move(i1, j1);
        }
    } 
}
int main() 
{
    nhap();
    move(s, t);
    cout << dem << endl;
    return 0;
}