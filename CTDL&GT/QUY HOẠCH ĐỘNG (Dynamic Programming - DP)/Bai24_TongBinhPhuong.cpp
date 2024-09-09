/*
[DP]. Bài 24. Tổng bình phương

Đề: Mọi số nguyên dương N đều có thể phân tích thành tổng các bình phương của các số nhỏ
hơn N. Ví dụ số 100 = 10^2 hoặc 100 = 5^2 + 5^2 + 5^2 + 5^2. Cho số nguyên dương N.
Nhiệm vụ của bạn là tìm số lượng ít nhất các số nhỏ hơn N mà có tổng bình phương bằng N.

*/
#include <bits/stdc++.h>
using namespace std;

int F[10001];

int main()
{
    int n; cin >> n;
    F[1] = 1;
    for (int i = 2; i <= n; i++) {
        F[i] = i;
        for (int j = 1; j <= sqrt(i); j++) {
            F[i] = min(F[i], 1 + F[i - j*j]);
            // cout << i << " = " << j << "^2" << " + " << i - j * j << endl;
        }
    }    
    cout << F[n];
    return 0;
}