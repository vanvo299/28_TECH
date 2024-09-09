/*
[DP]. Bài 23. Xâu con đối xứng dài nhất

Đề: Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự. Hãy tìm xâu con đối xứng dài nhất
của S
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    int n = s.size();
    s = "@" + s;
    int F[n + 1][n + 1];
    memset(F, false, sizeof(F));

    int ans = 1;
    // base case : trường hợp xâu có 1 kí tự
    for (int i = 1; i <= n; i++) F[i][i] = true;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if (len == 2) {
                // F[i][j] giúp xác định xâu con bắt đầu từ vị trí i kết thúc ở vị trí j có đối xứng hay không ?
                F[i][j] = (s[i] == s[j]);
            } 
            else {
                F[i][j] = (s[i] == s[j]) && F[i + 1][j - 1];
            }
            if (F[i][j]) {
                ans = max(ans, len);
            }
        }
    }
    cout << ans << endl;
    return 0;
}