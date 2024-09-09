/*
[Hàm, Lý thuyết số]. Bài 36. Tam giác Pascal

Đề: In ra tam giác Pascal với chiều cao là n. Nếu các giá trị của tam giác Pascal quá lớn, in ra 
giá trị trong tam giác này lấy dư với 1e9 + 7

*/
#include <bits/stdc++.h>
using namespace std;

int F[102][102];


// QHD, Đệ quy có nhớ
int tinh(int i, int j)
{
    if (j == 1 || j == i) return 1;
    if (F[i][j]) return F[i][j];
    return tinh(i - 1, j) + tinh(i - 1, j - 1);
}

int main()
{
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) F[i][j] = 1;
            else 
                F[i][j] = F[i - 1][j - 1] + F[i - 1][j];
                cout << F[i][j] << " ";
        }
        cout << endl;
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         cout << tinh(i, j) << ' ';
    //     }
    //     cout << endl;
    // }
    return 0;
}