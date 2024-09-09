/*
[DP]. Bài 1. Xâu con chung dài nhất

Đề: Cho 2 xâu S và T, hãy tìm độ dài xâu con chung dài nhất của S và T. Các kí tự của xâu con không nhất thiết phải
liền kề nhau
*/
#include <bits/stdc++.h>
using namespace std;

int F[1001][1001];

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    s = "0" + s;
    t = "0" + t;
    F[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                // F[i][j] = max({F[i - 1][j - 1] + 1, F[i - 1][j], F[i][j - 1]});
                F[i][j] = F[i - 1][j - 1] + 1;
            }
            else {
                F[i][j] = max(F[i - 1][j], F[i][j - 1]);
            }
        }
    }
    cout << F[n][m] << endl;
    return 0;
}