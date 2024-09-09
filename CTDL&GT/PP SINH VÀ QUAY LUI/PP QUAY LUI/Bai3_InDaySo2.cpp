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

int n,a[100], tmp[100];
vector<vector<int>> v;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tmp[i] = a[i];
    }

}

void ql(int pos) 
{
    if (pos == 0) return;
    vector<int> tmp;
    for (int i = 1; i < pos; i++) {
        a[i] += a[i + 1];
        tmp.push_back(a[i]);
    }
    v.push_back(tmp);
    ql(pos - 1);
}

void in() {
    // In các hàng theo thứ tự ngược lại
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << '[';
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            if (j != v[i].size() - 1) cout << ' ';
        }
        cout << ']' << endl;
    }
    
    // In mảng gốc cuối cùng
    cout << '[';
    for (int i = 1; i <= n; i++) {
        cout << tmp[i];
        if (i != n) cout << ' ';
    }
    cout << ']' << endl;
}
int main()
{
    int t; cin >> t;
    while(t--) {
        input();
        v.clear();
        ql(n);
        in();
    }
    return 0;
}