/*
[DP]. Bài 4. Dãy con có tổng bằng S

Đề: Cho mảng số nguyên A[] gồm N phần tử và số nguyên dương S, nhiệm vụ của bạn hãy xác 
định xem có thể tạo ra một tập con các phần tử trong mảng có tổng bằng S hay không ?
Chú ý mỗi phần tử trong mảng chỉ được sử dụng một lần.

*/
#include <bits/stdc++.h>
using namespace std;

int F[1001][1001];
int main()
{
    int n, s; cin >> n >> s;
    int A[n + 1];
    for (int i = 1; i <= n; i++) cin >> A[i];

    for (int i = 1; i <= n; i++) {
        F[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            if (j >= A[i]) {
            F[i][j] = F[i - 1][j - A[i]] || F[i - 1][j];
            }
            else F[i][j] = F[i - 1][j];
        }
    }
    cout << F[n][s] << endl;
    return 0;
}