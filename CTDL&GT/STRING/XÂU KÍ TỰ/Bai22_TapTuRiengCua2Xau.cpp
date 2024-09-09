/*
[Xâu kí tự]. Bài 22. Tập từ riêng của 2 xâu.

Đề: Cho 2 xâu kí tự S và T. Hãy liệt kê các từ xuất hiện ở xâu S và không xuất hiện ở xâu T mà không phân biệt hoa 
thường, mỗi từ được liệt kê một lần theo thứ tự từ điển tăng dần.

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    transform(t.begin(), t.end(), t.begin(), ::tolower);
    set<string> s1, s2;
    stringstream ss1(s), ss2(t);
    string word;
    while(ss1 >> word) {
        s1.insert(word);
    }
    while(ss2 >> word) {
        s2.insert(word);
    }

    for(string x : s1) {
        if (s2.count(x) == 0) {
            cout << x << ' ';
        }
    }
    return 0;
}