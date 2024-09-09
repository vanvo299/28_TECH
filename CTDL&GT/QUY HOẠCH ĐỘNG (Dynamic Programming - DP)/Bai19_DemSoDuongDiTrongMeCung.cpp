/*
[DP]. Bài 19. Đếm số đường đi trong mê cung

Đề: Cho mê cung được mô tả bởi một ma trận kí tự gồm N hàng và N cột. Mỗi ô trên ma trận chứa kí tự '.' tương
ứng với đường đi và dấu '*' tương ứng với bẫy. Một con chuột muốn đi từ ô (1, 1) tới ô (N, N) và chỉ được di
chuyển khi một ô nào đó là đường đi và nó được di chuyển sang phải hoặc xuống dưới. Hãy đếm số cách con chuột 
có thể di chuyển tới đích. Vì kết quả quá lớn nên hãy lấy dư với 10^9 + 7

*/
#include <bits/stdc++.h>
using namespace std;

int F[1001][1001];
char a[1001][1001];

int main()
{
    int n; cin >> n;
    int mod = 1e9 + 7;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    F[0][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '.') 
                F[i][j] = F[i - 1][j] + F[i][j - 1];
            else 
                F[i][j] = 0;
            F[i][j] %= mod;
        }
    }

    cout << F[n][n];
    return 0;
}