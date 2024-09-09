/*
[DP]. Bài 15. Coin Problem

Bài: Ngân hàng XYZ hiện có N tờ tiền có mệnh giá khác nhau được lưu vào mảng C[], bạn hãy 
tìm cách đổi số tiền là S sao cho số tờ tiền cần dùng là ít nhất. Bạn được sử dụng một
mệnh giá là không giới hạn số lần

- In ra số tờ tiền nhỏ nhất. Nếu  không thể đổi được số tiền đúng bằng S thì in ra -1
*/
#include <bits/stdc++.h>
using namespace std;

int F[1001];
int main()
{
    int n, s; cin >> n >> s;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= s; i++) {
        F[i] = 1e9;
    }
    F[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            if (j >= a[i])
                F[j] = min(F[j - a[i]] + 1, F[j]);
        }
    }
    if (F[s] == 1e9) cout << "-1" << endl;
    else cout << F[s] << endl; 
    return 0;
}