/*
[DP]. Bài 14. Xúc xắc

Đề: Bài toán có yêu cầu rất đơn giản, cho ngẫu nhiên số N, hỏi rằng nếu được tung một con xúc xắc không
giới hạn số lần và lấy tổng số chấm trên mặt xúc xắc cộng lại với nhau, hỏi có bao nhiêu cách
tung để tổng số chấm trong mọi lần tung xúc xắc bang N. Vì số cách tung có thể quá lớn, nên bạn hãy chia dư kết quả với modulo 10^9 + 7

*/
#include <bits/stdc++.h>
using namespace std;

int F[1001];

int main()
{
    int n; cin >> n;
    int mod = 1e9 + 7;
    F[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i >= j) {
                F[i] += F[i - j];
            }
            F[i] %= mod;
        }
    }
    cout << F[n] << endl;
    for (int x : F) cout << x << ' ';
    return 0;
}