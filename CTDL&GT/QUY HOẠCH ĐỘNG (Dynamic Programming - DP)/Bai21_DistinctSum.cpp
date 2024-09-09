/*
[DP]. Bài 21. Distinct Sum

Đề: Cho mảng A[] gồm N phần tử là số nguyên dương, xét tất cả các tập con của A[] và tính
tổng các phần tử trong tập này (bao gồm cả tập rỗng), sau đó liệt kê các tổng khác nhau có
thể tạo thành theo thứ tự tăng dần.
*/
#include <bits/stdc++.h>
using namespace std;

int F[1001];

int main()
{
    int n, s = 0;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    F[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= 1; j--) {
            if (j >= a[i]) {
                F[j] = F[j - a[i]] || F[j];
            }
        }
    }
    for (int i = 0; i <= s; i++) {
        if (F[i]) {
            cout << i << ' ';
        }
    } 
    return 0;
}