/*
[Sắp xếp - Tìm kiếm]. Bài 48. Xếp hình Domino.

Đề: Trong lớp học của Tèo có các thanh Domino hình chữ nhật có chiều rộng a và có chiều dài b. Tèo hiện là học 
sinh lớp 1, thầy giáo có giao cho Tèo một bài toán đó là hãy tìm 1 bản hình vuông có cạnh nhỏ nhất sao cho
có thể xếp n thanh domino vào hình vuông này. Tèo không nhất thiết phải xếp kín cái bảng hình vuông này
nhưng không được phép xoay ngang thanh domino. 
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(int a, int b, int n, ll mid) 
{
    ll x = mid / a;
    ll y = mid / b;
    return x * y >= n;
}
int main()
{
    int a, b,n; cin >> a >> b >> n;
    ll left = 0, right = 1ll * max(a, b) * n;
    ll ans = -1;

    while(left <= right) {
        ll mid = (left + right) / 2;

        if (check(a, b, n, mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}