/*
[STACK]. Bài 9. Tiền tố - Trung tố

ĐỀ: Cho biểu thức S ở dạng tiền tố, hãy biến đổi S về dạng trung tố và in ra màn hình

Thuật toán: Duyệt từ cuối về đầu của biểu thức tiền tố, nếu gặp toán hạng thì đẩy vào ngăn xếp, nếu gặp toán tử
thì lấy và xóa 2 toán hạng ở đỉnh ngăn xếp và áp dụng toán tử này với 2 toán hạng đó (Chú ý thứ tự và bổ sung đóng mở
ngoặc tròn), đẩy ngược biêu thức thu được lại vào ngăn xếp. Biểu thức ở đỉnh ngăn xếp cuối cùng là biểu thức trung tố thu được

*/
// #include <bits/stdc++.h>
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

string TienTo_TrungTo()
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
            string res = "(" + s1 + s[i] + s2 + ")";
            st.push(res);
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