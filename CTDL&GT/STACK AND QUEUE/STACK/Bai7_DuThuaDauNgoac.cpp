/*
[STACK]. Bài 7. Dư thừa dấu ngoặc

ĐỀ: Cho một biểu thức số học đúng nhưng có thể dư thừa dấu ngoặc, nhiệm vụ của bạn là 
kiểm tra xem biểu thức này có dư thừa dấu đóng mở ngoặc hay không ?

*/
#include <bits/stdc++.h>
using namespace std;

bool solve(string s)
{
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) return false;
            if (c == ')' && st.top() != '(') {
                return false;
            }
            if (c == '}' && st.top() != '{') {
                return false;
            }
            if (c == ']' && st.top() != '[') {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    string s;
    cin >> s;
    if (solve(s)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}