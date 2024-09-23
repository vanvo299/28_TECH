/*
[STACK]. Bài 8. Lật ngược dấu ngoặc

ĐỀ: Cho xâu S chỉ bao gồm dấu đóng mở ngoặc, hãy tìm số lượng dấu ngoặc tối thiêu cần phải
đổi chiều để tạo thành một xâu hợp lệ.

*/
#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    stack<char> st;
    int cnt = 0;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                cnt++;
                st.push(c);
            }
            else {
                st.pop();
            }
        }
    }
    cnt += st.size() / 2;
    return cnt;
}
int main()
{
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}