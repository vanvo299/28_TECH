/*
[Quay lui - Nhánh cận]. Bài 17. Parentheses

Đề: Bạn hãy sinh ra các biểu thức dấu ngoặc hợp lệ từ các cặp dấu ngoặc "()", "[]", "{}" có độ dài N. Kết quả được in 
ra theo thứ tự từ điển tăng dần, nếu không tồn tại biểu thức hợp lệ thỏa mản thì in ra NOT FOUND
*/
#include <bits/stdc++.h>
using namespace std;

string s;
string tmp = "()[]{}";
int n;

vector<string> res;

// kiểm tra xem chuỗi dấu đóng mở ngoặc có hợp lệ không ? 
bool check(string s)
{
    stack<char> st;
    for (char x : s) {
        if (x == '(' || x == '[' || x == '{') {
            st.push(x);
        }
        else {
            if (st.empty()) return false;
            char y = st.top();
            st.pop();
            if ((x == ')' && y != '(') || (x == ']' && y != '[') || (x == '}' && y != '{')) return false;
        }
    }
    if (st.empty()) return true;
    return false;
}

void Try(int i)
{
    for (int j = 0; j < tmp.size(); j++) {
        s += tmp[j];
        if (s.size() == n) {
            if (check(s)) {
                res.push_back(s);
            }
         }
        else {
            Try(i + 1);
        }
        // backtrack
        s.pop_back();
    }
}
int main()
{
    cin >> n;
    if (n % 2 == 1) {
        cout << "NOT FOUND" << endl;
    } else {
        Try(1);
        sort(res.begin(), res.end());
        for (string x : res) cout << x << ' ';
    }
    return 0;
}