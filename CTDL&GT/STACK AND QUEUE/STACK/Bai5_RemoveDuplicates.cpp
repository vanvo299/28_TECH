/*
[STACK]. Bài 5. Remove Duplicates

ĐỀ: Cho một xâu kí tự S chỉ bao gồm kí tự in thường, nhiệm vụ của bạn là xóa các kí tự liền kề
giống nhau khỏi xâu S. Ví dụ xâu aabbccc sau khi xóa các kí tự liền kề sẽ thành c, xâu abba 
sau khi xóa các kí tự liền kề sẽ trở thành xâu rỗng.

*/
#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    stack<char> st;
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            if (!st.empty() && s[i] == st.top()) {
                st.pop();
            } else st.push(s[i]);
        }
    }
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
    
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    string s; cin >> s;
    string res = solve(s);
    if (res.size()) {
        cout << res;
    } else {
        cout << "EMPTY\n";
    }
    return 0;
}