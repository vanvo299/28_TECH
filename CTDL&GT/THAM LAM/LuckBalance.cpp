/*
[Tham lam]. Luck Balance

Đề: Lena is preparing for an important coding competition that is preceded by a number of sequential preliminary
contests. Initialy, her luck balance is 0. She believes in "saving luck", ans wants to check her theory. Each
contest is described by two integers, L[i] and T[i]
- L[i] is the amount of luck associated with a contest. If Lenaa wins the contest, her luck balance will decrese
by L[i]; If she loses it, her luck balance will increase by L[i]
- T[i] denotes the contest's importance rating. It's equal to 1 if the contest is Important, and it's equal to 0 if 
it's important.
If Lena lose no more than k important contests, what is the maximum amount of luck she can have after
competing in all the preliminary contest ? This value may be negative.
*/

// Những contest không quan trọng thì cho thua để tăng chỉ số may mắn, và chọn ra k contest có chỉ số may mắn cao nhất và thua nó
// để tăng chỉ số may mắn, và thắng những contest còn lại.

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n, k; 
    cin >> n >> k;
    vector<int> v;
    ll ans = 0; // save luck value

    for (int i = 0; i < n; i++) {
        int l, t; cin >> l >> t;
        if (t == 0) {
            // thua những contest không quan trọng
            ans += l;
        }
        else {
            // những contest quan trọng thì cho vào vector
            v.push_back(l);
        }
    }

    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++) {
        if (i < k) {
            // cho thua k contest lớn nhất
            ans += v[i];
        }
        // thắng những contest còn lại
        else ans -= v[i];
    }
    cout << ans << endl;
    return 0;
}