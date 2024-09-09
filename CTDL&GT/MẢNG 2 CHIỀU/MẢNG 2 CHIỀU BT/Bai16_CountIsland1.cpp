/*
[Mảng 2 chiều]. Bài 16. Count Island 1

Đề: Cho ma trận nhị phân gồm N hàng và M cột chỉ bao gồm các số 0 và 1. Hãy đếm số lượng miền các số  1 trong 
ma trận, các ô số 1 được coi là cùng miền nếu chúng có chung cạnh
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100][100];

void nhap() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}

// chung canh nen duyet 4 o xung quanh
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void loang(int i, int j)
{
    a[i][j] = 0; // a[i][j] da duoc di qua
    cout << "Di qua o " << i << ' ' << j << endl;
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1]) {
            loang(i1, j1);
        } 
    }
}
int main()
{
    nhap();
    int dem = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                ++dem;
                loang(i, j);
                cout << endl;
            }
        }
    }
    cout << dem << endl;
    return 0;
}