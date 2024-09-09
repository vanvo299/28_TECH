/*
[DP]. Bài 27. Xóa chữ số

Đề: Bạn đượccung cấp một số nguyên n. Trên mỗi bước bạn có thể trừ một trong các chữ số
khỏi số. Cần thực hiện bao nhiêu bước để số đó bằng 0.
*/
#include <bits/stdc++.h>
using namespace std;

int F[1000001];

// Quy hoạch động từ trên xuống dưới 
// int tinh(int n)
// {
//     if (n == 0) return 0;
//     if (F[n] != 0) return F[n];
//     int m = n;
//     int res = 1e9;
//     while(m) {
//         int r = m % 10;
//         if (r != 0) {
//             res = min(res, tinh(n - r) + 1);
//         }
//         m /= 10;
//     }
//     F[n] = res;
//     return res;
// }
int main()
{
    int n; cin >> n;
    // cout << tinh(n);

    // Quy hoạch động từ dưới lên
    for (int i = 1; i <= n; i++) {
        int m = i;
        F[i] = 1e9;
        while(m) {
            int r = m % 10;
            if (r != 0) 
                F[i] = min(F[i], F[i - r] + 1);
            m /= 10;
        }
    }
    cout << F[n];
    return 0;
}