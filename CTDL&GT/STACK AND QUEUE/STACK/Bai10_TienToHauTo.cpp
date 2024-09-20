/*
[STACK]. Bài 10. Tiền tố - Hậu tố
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

std::string s;
stack<string> st;

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

std::string TienTo_TrungTo()
{
    for (int i = s.size() - 1; i >= 0; i--) {
        // if (s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
        if (isalpha(s[i])) {
            st.push(string(1, s[i])); // Chuyển ký tự thành chuỗi và đẩy vào stack
            // Tạo ra chuỗi có 1 kí tự
        } 
        if (isOperator(s[i])) {
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            string tmp = "(" + s1 + s2 + s[i] + ")";
            st.push(tmp);
        }
    }
    return st.top();
}
int main()
{
    cin >> s;
    cout << TienTo_TrungTo() << endl;
    return 0;
}