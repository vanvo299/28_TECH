/*
[STACK]. Bài 14. Tính toán giá trị biểu thức tiền tố

ĐỀ: Cho biểu thức tiền tố S, các số trong biểu thức chỉ là số có 1 chữ số, yêu cầu tính toán giá trị của biểu thức

*/
#include <bits/stdc++.h>
using namespace std;

string s;
stack<int> st;

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
int solve()
{
    for (int i = s.size() - 1; i >= 0; i--) {
        if (isdigit(s[i])) {
            st.push(s[i] - '0');
        }
        else if (isOperator(s[i])) {
            int o1 = st.top(); st.pop();
            int o2 = st.top(); st.pop();
            if (s[i] == '+') st.push(o1 + o2);
            if (s[i] == '-') st.push(o1 - o2);
            if (s[i] == '*') st.push(o1 * o2);
            if (s[i] == '/') st.push(o1 / o2);
        }
    }
    return st.top();
}
int main()
{
    cout << "Nhap vao bieu thuc tien to: ";
    cin >> s;
    cout << "Gia tri cua bieu thuc tien to la: " << solve() << endl;
    return 0;
}