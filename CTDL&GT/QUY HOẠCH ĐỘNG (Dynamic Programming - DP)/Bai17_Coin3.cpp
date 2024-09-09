/*
[DP]. Bài 17. Coin 3

Đề: Hãy xem xét một hệ thống tiền tệ của ngân hàng ABC bao gồm n đồng xu. Mỗi đồng xu có
một giá trị nguyên dương. Nhiệm vụ của bạn là tính số cách riêng biệt không xét đến thứ
tự mà bạn có thể tạo ra số tiền x bằng cách sử dụng số tiền có sẵn. Ví dụ: nếu số xu là
{2, 3, 5} và tổng mong muốn là 9, có 3 cách: 2 + 2 + 5; 3 + 3 + 3; 2 + 2 + 2 + 3

*/
#include <bits/stdc++.h>
using namespace std;

int F[1001][1001];
int main()
{
    int n, s; cin >> n >> s;
    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        F[i][0] = true;
    }

    int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            if (j >= A[i]) {
            F[i][j] = F[i][j - A[i]] + F[i - 1][j];
            }
            else F[i][j] = F[i - 1][j];
            F[i][j] %= mod;
        }
    }
    cout << F[n][s];
    return 0;
}