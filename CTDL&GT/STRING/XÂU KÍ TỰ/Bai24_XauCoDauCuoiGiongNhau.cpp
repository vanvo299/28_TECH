/*
[Xâu ký tự]. Bài 24. Xâu có đầu cuối giống nhau.

Đề: Cho xâu S chỉ bao gồm các kí tự in thường, hãy đếm số lượng xâu con (xâu kí tự chứa các chữ cái liên tiếp) mà
có kí tự đầu và kí tự cuối giống nhau. 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main()
{
    string s; cin >> s;
    map<char, int> mp;

    for (char x : s) {
        mp[x]++;
    }
    ll ans = s.size(); // tinh ca cac xau co 1 ki tu 
    for (auto it : mp) {
        ans += 1ll * it.second * (it.second - 1) / 2; 
        // Tinh to hop chap 2 cua n = n * (n - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}