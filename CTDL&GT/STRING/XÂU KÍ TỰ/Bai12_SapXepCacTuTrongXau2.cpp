/*
[Xâu kí tự]. Bài 12. Sắp xếp các từ trong xâu 2

Đề: Cho một xâu kí tự S bao gồm các chữ cái và dấu cách, một từ được định nghĩa là các kí tự liên tiếp không chứa
dấu cách, hãy sắp xếp các từ thuận nghịch khác nhau trong xâu theo thứ tự chiều dài từ tăng dần, nếu 2 từ 
thuận nghịch có cùng chiều dài thì từ nào xuất hiện trước sẽ được in ra trước.

*/
#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
    return a.size() < b.size();
}

bool KT_ThuanNghich(string s)
{
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}
int main()
{
    string s;
    vector<string> v;
    set<string> se;
    while(cin >> s) {
        if (se.count(s) == 0 && KT_ThuanNghich(s)) {
            v.push_back(s);
        }
        se.insert(s);
    }

    stable_sort(v.begin(), v.end(), cmp);
    for (string x : v) cout << x << " ";
    return 0;
}