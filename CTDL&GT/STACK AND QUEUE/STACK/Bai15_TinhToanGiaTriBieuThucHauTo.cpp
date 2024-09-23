/*
[STACK]. Bài 15. Tính toán giá trị biểu thức hậu tố

ĐỀ: Cho biểu thức hậu tố S, các số trong biểu thức chỉ là số có 1 chữ số, yêu cầu tính toán giá
trị của biểu thức

*/
#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    stack<int> st;
    for (char c : s) {
        if (isdigit(c)) {
            st.push(c - '0');
        }
        else {
            int o1 = st.top(); st.pop();
            int o2 = st.top(); st.pop();
            if (c == '+') st.push(o2 + o1);
            if (c == '-') st.push(o2 - o1);
            if (c == '*') st.push(o2 * o1);
            if (c == '/') st.push(o2 / o1);
        }
    }
    return st.top();
}
int main()
{
    string s;
    cout << "Nhap vao bieu thuc tien to: ";
    cin >> s;
    cout << "Gia tri cua bieu thuc hau to la: " << solve(s);
    return 0;
}