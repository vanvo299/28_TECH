/*
[DP]. Bài 16. Coin 2

Đề: Hãy xem xét một hệ thống tiền tệ của ngân hàng XYZ bao gồm n đồng xu có
một giá trị nguyên dương. Nhiệm vụ của bạn là tính số cách riêng biệt mà bạn có thể tạo
ra số tiền x bằng cách sử dụng số xu có sẵn. Ví dụ: nếu số xu {2, 3, 5} và tổng mong muốn
là 9, có 8 cách: 2 + 2 + 5; 2 + 5 + 2; 5 + 2 + 2; 3 + 3 + 3; 2 + 2 + 2 + 3; 2 + 2 + 3 + 2; 2 + 3 + 2 + 2;
3 + 2 + 2 + 2
*/

// bài này giống hệt bài bước bậc thang
#include <bits/stdc++.h>
using namespace std;

int F[1001];

int main()
{
    int n, x; cin >> n >> x;
    int a[n + 1]; // mảng chưá các mệnh giá tiền
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    F[0] = 1;
    int mod = 1e9 + 7;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= a[j]) {
                F[i] += F[i - a[j]];
            }
            F[i] %= mod;
        }
    }
    cout << F[x];
    return 0;
}