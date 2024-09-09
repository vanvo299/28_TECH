/*
[Xâu kí tự]. Bài 21. Tập từ chung của 2 xâu

Đề: Cho 2 xâu kí tự S và T. Hãy liệt kê các từ xuất hiện ở cả 2 xâu mà không phân biệt hoa thường, mỗi từ được liệt
kê một lần theo thứ tự từ điển tăng dần.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, T; 
    getline(cin, S);
    getline(cin, T);
    set<string> s1;
    set<string> s2;

    transform(S.begin(), S.end(), S.begin(), ::tolower);
    transform(T.begin(), T.end(), T.begin(), ::tolower);
    
    stringstream ss1(S), ss2(T);
    string word;
    while(ss1 >> word) {
        s1.insert(word);
    }
    while(ss2 >> word) {
        s2.insert(word);
    }

    for (string x : s1) {
        if (s2.count(x)) {
            cout << x << " ";
        }
    }

    return 0;
}