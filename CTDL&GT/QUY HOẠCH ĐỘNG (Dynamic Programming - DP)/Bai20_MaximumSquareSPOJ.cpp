/*
[DP]. Bài 20. Maximum Square SPOJ

Đề: Bạn được cung cấp một ma trận nhị phân có N dòng và M cột chỉ bao gồm các số 0 và 1
, hãy tìm hình vuông lớn nhất trong ma trận mà chỉ chứa toàn số 1

*/
#include <bits/stdc++.h>
using namespace std;

int a[1001][1001], F[1001][1001];
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1;  j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                F[i][j] = min({F[i - 1][j], F[i][j - 1], F[i - 1][j - 1]}) + 1;
            }
            else F[i][j] = 0;
            res = max(res, F[i][j]);
        }
    }
    return 0;
}