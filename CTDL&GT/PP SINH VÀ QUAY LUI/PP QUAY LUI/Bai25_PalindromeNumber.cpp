/*
[Quay lui - Nhánh cận]. Bài 25. Palindrome Number

Đề: Cho một số nguyên dương N, có không quá 16 chữ số, bạn được phép tách các chữ số của N thành các số nhỏ
hơn và phải đảm bảo các số được tách đều là số thuận nghịch, bạn cũng ko được phép đảo thứ tự các chữ số của N.
Hãy in ra mọi cách tách như vậy.
*/
#include <bits/stdc++.h>
using namespace std;

// hàm kiểm tra xem 1 xâu có phải là xâu đối xứng không ?
bool check(string s)
{
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

vector<vector<string>> res;
vector<string> v;

void Try(int start, string s)
{
    if (start >= s.size()) res.push_back(v);
    for (int end = start; end < s.size(); end++) {
        if (check(s.substr(start, end - start + 1))) {
            v.push_back(s.substr(start, end - start + 1));
            Try(end + 1, s);
            v.pop_back();
        }
    }
}
int main()
{
    string s; cin >> s;
    Try(0, s);
    for (auto it : res) {
        for (string x : it) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}