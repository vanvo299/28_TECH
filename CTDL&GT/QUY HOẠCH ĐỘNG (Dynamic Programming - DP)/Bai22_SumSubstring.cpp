/*
[DP]. Bài 22. Sum substring

Đề: Cho một số tự nhiên N được biểu diễn như một xâu kí tự, bạn hãy tính tổng của tất cả các
số tạo bơit các xâu con liên tiếp của N. Ví dụ, N = 235 thì ta có tổng = 2 + 3 + 5 + 23 + 25 + 235

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    int n = s.size();
    s = '0' + s;
    long long sum = 0;
    int F[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        F[i] = F[i - 1] * 10 + i * (s[i] - '0');
        sum += F[i];
    }
    cout << sum << endl;
    return 0;
}