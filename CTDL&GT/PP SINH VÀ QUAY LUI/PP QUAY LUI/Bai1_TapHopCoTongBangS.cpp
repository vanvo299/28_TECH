/*
[Quay lui - Nhánh cận]. Bài 1. Tập hợp có tổng bằng S
Xét tất cả các tập hợp các số nguyên dương có các phần tử khác nhau và không lớn hơn số n cho trước. Nhiệm vụ của bạn là hãy đếm xem có tất cả bao nhiêu tập hợp có số lượng phần tử bằng k và tổng của tất cả các phần tử trong tập hợp bằng s?
Các tập hợp là hoán vị của nhau chỉ được tính là một.
Ví dụ với n = 9, k = 3, s = 23, {6, 8, 9} là tập hợp duy nhất thỏa mãn.

*/
#include <bits/stdc++.h>
using namespace std;

int a[100], x[100];
int n, k, s, ans = 0;

void input() 
{
    cin >> n >> k >> s;
    for (int i = 1; i < n + 1; i++) {
        a[i] = i;
    }
}

void ql(int pos, int cnt, int sum) 
{
    if (cnt == k && sum == s) {
        ++ans;
        return;
    }
    for (int i = pos; i <= n; i++) {
        if (a[i] + sum <= s) {
            x[cnt] = i;
            ql(i + 1, cnt + 1, sum + a[i]);
        }
    }
}
int main()
{
    while(true) {
        input();
        if (n == 0 && k == 0 && s == 0) {
            break;
        }
        ans = 0;
        ql(1, 0, 0);
        cout << ans << endl;
    }
    return 0;
}