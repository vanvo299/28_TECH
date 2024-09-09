/*
[Xâu kí tự]. Bài 14. Từ xuất hiện nhiều nhất, ít nhất.

Đề: Cho một xâu kí tự S bao gồm các chữ cái và dấu cách, một từ được định nghĩa là các kí tự liên tiếp không chứa
dấu cách. Hãy tìm từ có số lần xuất hiện nhiều nhất, ít nhất trong xâu, nếu có nhiều từ có cùng số lần xuất
hiện nhiều nhất hoặc ít nhất thì chọn từ có thứ tự từ điển lớn nhất làm kết quả.

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    vector<string> v;
    map<string, int> mp;

    while(cin >> s) {
        mp[s]++;
    }
    int ts_min = 1e9, ts_max = 0;
    string res1, res2;
    for (auto it : mp) {
        if (it.second <= ts_min) {
            ts_min = it.second;
            res1 = it.first;
        }
        if (it.second >= ts_max) {
            ts_max = it.second;
            res2 = it.first;
        }
    }

    cout << res2 << " " << ts_max << endl;
    cout << res1 << " " << ts_min << endl;
    return 0;
}