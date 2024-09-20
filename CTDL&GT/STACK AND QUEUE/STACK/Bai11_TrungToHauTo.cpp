/*
[STACK]. Bài 11. Trung tố - Hậu tố

Đề: Cho biểu thức S ở dạng trung tố, hãy biến đổi S về dạng hậu tố và in ra màn hình

**Thuật toán (Áp dụng cho cả biểu thức trung tố không đầy đủ ngoặc):
- Duyệt biểu thức trung tố từ đầu tới cuối
+ Nếu là toán hạng thì thêm vào xâu kết quả
+ Nếu là dấu '(' thì thêm vào ngăn xếp
+ Nếu là dấu ')' thì lần lượt pop các kí tự trong ngăn xếp và đưa vào xâu kết quả cho tới khi 
gặp dấu '(' tương ứng.
+ Nếu là toán tử: Lần lượt pop các toán tử ở đỉnh ngăn xếp nếu thứ tự ưu tiên của nó lớn
hơn hoặc bằng thứ tự ưu tiên của kí tự đang xét. Đẩy toán hạng này vào ngăn xếp
- Lần lượt đưa mọi kí tự trong ngăn xếp và thêm vào cuối xâu kết quả 
*/
#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> st;
string res = "";

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Độ ưu tiên của toán tử
int prec(char ch)
{
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

string solve()
{
    for (int i = 0; i < s.size(); i++) {
        // Nếu là toán hạng (Chữ cái)
        if(isalpha(s[i])) {
            res += s[i];
        }
        // Nếu là dấu mở ngoặc '('
        else if (s[i] == '(') {
            st.push(s[i]);
        }

        // Nếu là dấu đóng ngoặc ')'
        else if (s[i] == ')') {
            while(st.top() != '(' && !st.empty()) {
                char tmp = st.top(); st.pop();
                res += tmp;
            }
            // Pop dấu '(' ra khỏi Stack
            if (!st.empty()) st.pop();
        }

        // Nếu là toán tử
        else if (isOperator(s[i])) {
            while(!st.empty() && prec(st.top()) >= prec(s[i])) {
                char tmp = st.top(); st.pop();
                res += tmp;
            } 
            st.push(s[i]);
        }
    }

    // Đưa các toán tử còn lại trong ngăn xếp vào kết quả
    while(!st.empty()) {
        char tmp = st.top(); st.pop();
        res += tmp;
    }
    return res;
}
int main()
{
    cout << "Nhap vao bieu thuc trung to: ";
    cin >> s;
    cout << "Bieu thuc hau to: ";
    cout << solve() << endl;
    return 0;
}