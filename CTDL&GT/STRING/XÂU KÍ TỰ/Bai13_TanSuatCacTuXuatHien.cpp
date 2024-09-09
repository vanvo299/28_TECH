/*
[Xâu ký tự]. Bài 13. Tần suất các từ xuất hiện trong xâu.

Đề: Cho một xâu ký tự S bao gồm các chữ cái và dấu cách, một từ được định nghĩa là các kí tự liên tiếp không chứa
dấu cách, hãy đếm xem mỗi từ trong xâu xuất hiện bao nhiêu lần, đầu tiên hãy liệt kê các từ trong xâu kèm
theo tần xuất của mỗi từ theo thứ tự từ điển, sau đó liệt kê các từ trong xâu theo thứ tự xuất hiện.
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
        v.push_back(s);
    }

    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;
    for (string x : v) {
        if (mp[x] != 0) {
            cout << x << " " << mp[x] << endl;
            mp[x] = 0;
        }
    }
    
    return 0;
}