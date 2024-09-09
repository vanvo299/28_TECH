/*
Bài 2. In dãy số
Cho dãy số A[] gồm n số nguyên dương. Tam giác đặc biệt của dãy số A[] là tam giác được tạo ra bởi n hàng, 
trong đó hàng thứ 1 là dãy số A[], hàng i là tổng hai phần tử liên tiếp của hàng i-1 (2≤i≤n).
Ví dụ A[] = {1, 2, 3, 4, 5}, khi đó tam giác được tạo nên như dưới đây:
[1, 2, 3, 4, 5 ]
[3, 5, 7, 9 ]
[8, 12, 16]
[20, 28]
[48]

*/
#include <bits/stdc++.h>
using namespace std;

int n,a[100];

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void ql(int pos) 
{
    if (pos == 0) return;

    cout << '[';
    for (int j = 1; j <= pos; j++) {
        cout << a[j];
        if (j != pos) cout << ' ';
    }
        cout << ']' << endl;
    for (int i = 1; i < pos; i++) {
        a[i] += a[i + 1];
    }
    ql(pos - 1);
}
int main()
{
    int t; cin >> t;
    while(t--) {
        input();
        ql(n);
    }
    return 0;
}