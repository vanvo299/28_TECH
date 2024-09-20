/*
[Ngăn xếp]. Bài 3. Valid parentheses

Đề: Cho một xâu kí tự chỉ bao gồm kí tự '(', ')', '{', '}', '[', ']', hãy xác định xem các dấu ngoặc trong xâu có ccaan
bằng hay không. 

Ý tưởng: Sử dụng ngăn xếp để lưu các dấu mở ngoặc, nếu gặp dấu đóng ngoặc thì kiểm tra trong stack có dấu mở ngoặc tương ứng 
hay không, nếu có thì xóa dấu mở ngoặc đó đi, ngược lại có thể kết luận biểu thức là không đúng. 
*/
#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> st;

// Hàm kiểm tra dấu ngoặc hợp lệ
bool check()
{
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;

            if (c == ')' && st.top() != '(' ||
                c == ']' && st.top() != '[' ||
                c == '}' && st.top() != '{') {
                    return false;
                } 
            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    cin >> s;
    if (check()) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
    
    return 0;
}