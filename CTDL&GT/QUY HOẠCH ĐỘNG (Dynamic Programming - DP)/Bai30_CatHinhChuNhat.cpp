/*
[DP]. Bài 30. Cắt hình chữ nhật

Đề: Cho một hình chữ nhật a x b, nhiệm vụ của bạn là cắt nó thành các hình vuông. Trên mỗi lần cắt, bạn có thể
chọn một hình chữ nhật và cắt nó thành hai hình chữ nhật sao cho tất cả độ dài các cạnh vẫn là số nguyên. Số
lần di cắt tối thiểu có thể là bao nhiêu ?

- In ra số lần cắt tối thiểu
*/
#include <bits/stdc++.h>
using namespace std;
int n, m, F[1005][1005];

int tinh(int n, int m)
{
    if (n == m) return 0;
    if (F[n][m] != 0) return F[n][m];
    int res = 1e9;
    // khi cắt dọc
    for (int i = 1; i <= m - 1; i++) {
        res = min(res, tinh(n, i) + tinh(n, m - i) + 1);
    }
    // khi cắt ngang
    for (int i = 1; i <= n - 1; i++) {
        res = min(res, tinh(i, m) + tinh(n - i, m) + 1);
    } 
    F[n][m] = res;
    return F[n][m];
}
int main()
{
    cin >> n >> m;
    cout << tinh(n, m);
    return 0;
}