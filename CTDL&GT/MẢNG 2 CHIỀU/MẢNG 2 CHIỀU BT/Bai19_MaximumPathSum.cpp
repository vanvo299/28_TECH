/*
[Mảng 2 chiều]. Bài 19. Maximum path sum

Đề: Cho ma trận A các số nguyên có N hàng và M cột. Tìm đường đi rừ ô [1, 1] tới ô [N, M] sao cho tổng các số trên 
đường đi là lớn nhất có thể, biết rằng ở mỗi bước chỉ có thể đi từ ô hiện tại xuống ô phía duói hoặc đi sang
phải.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int A[505][505];
ll F[ 505][505];
int n, m;


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            F[i][j] = max(F[i - 1][j], F[i][j - 1]) + A[i][j];
        } 
    }
    cout << F[n][m] << endl;

    return 0;
}