// STACK
#include <iostream>
#include <stack>

using namespace std;

bool check(string s)
{
    stack<char>  st;
    for (char x : s) {
        if (x == '(' || x == '{' || x == '[') {
            st.push(x);
        } else {
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    string s;
    getline(cin, s);
    if (check(s)) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
    return 0;
}