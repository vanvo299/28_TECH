/*
[DP]. Bài 18. Maximum Path Sum

Đề: Cho mảng A[][] kích thước N x M (N hàng, M cột). Bạn được phép đi xuống dưới, đi sang phải và đi xuống ô chéo
dưới về bên phải. Khi đi qua ô (i, j), điểm nhận được bằng A[i][j]. Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao
cho tổng điểm là lớn nhất;
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int A[505][505];
ll F[505][505];
int n, m;

int main()
{
     cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    
    // dp[i][j] = a[i][j] + max(dp[i - 1])[j], dp[i][j - 1], dp[i - 1][j - 1])
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            F[i][j] = max({F[i - 1][j], F[i][j - 1], F[i - 1][j - 1]}) + A[i][j];
        }
    }
    cout << F[n][m] << endl;
   return 0;
}