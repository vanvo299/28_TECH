/*
[Xâu kí tự]. Bài 10. Liệt kê các từ khác nhau trong xâu.

Đề: Cho một xâu kí tự S bao gồm các chữ cái và dấu cách, một từ được định nghĩa là các kí tự liên tiếp không chứa
dấu cách, hãy liệt kê các từ khác nhau trong xâu S, đầu tiên hãy liệt kê các từ khác nhau theo thứ tự từ điển
tăng dần, sau đó liệt kê các từ theo thứ tự xuất hiện trong xâu.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    vector<string> v;
    set<string> se;

    while(cin >> s) {
        if (se.count(s) == 0) {
            v.push_back(s);
        }
        se.insert(s);
    }
    for (string x : se) {
        cout << x << " ";
    } 
    cout << endl;
    for (string x : v) {
        cout << x << " ";
    }

    return 0;
}