/*
[STACK]. Bài 16. Đảo từ

ĐỀ: Cho một đoạn văn có không quá 10000 từ, nhiệm vụ của bạn là in ra các từ trong đonaj 
văn theo thứ tư ngược

*/
#include <bits/stdc++.h>
using namespace std;

string solve()
{
    string res = "";
    stack<string> st;
    string s;
    while(cin >> s) {
        st.push(s);
    }

    while(!st.empty()) {
        res += st.top() + " ";
        st.pop();
    }
    return res;
}
int main()
{
    cout << solve() << endl;
    return 0;
}