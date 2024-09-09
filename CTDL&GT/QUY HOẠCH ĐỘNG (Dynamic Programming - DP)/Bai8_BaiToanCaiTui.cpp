/*
[DP]. Bài 8. Bài toán cái túi

Đề: Một tên trộm có 1 cái túi có thể mang các đồ vật với trọng lượng tối đa là V. Hiện tại tên
trộm muốn lựa chọn các đồ vật trong N đồ vật để ăn trộm, mỗi đồ vật có trọng lượng là
W[i] và giá trị là V[i]. Hãy xác định tổng giá trị lớn nhất của các đồ vật mà tên trộm nay này lựa
chọn sao cho trọng lượng của chúng không vượt quá V.
*/
#include <bits/stdc++.h>
using namespace std;
int F[1001][1001];
int main()
{
    int n, V;
    cin >> n >> V;
    int w[n + 1], v[n + 1];

    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> v[i];

    F[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            if (j >= w[i]) {
                F[i][j] = max(v[i] + F[i - 1][j - w[i]], F[i - 1][j]);
            }
            else {
                F[i][j] = F[i - 1][j];
            }
        }
    }
    cout << F[n][V] << endl;
    return 0;
}