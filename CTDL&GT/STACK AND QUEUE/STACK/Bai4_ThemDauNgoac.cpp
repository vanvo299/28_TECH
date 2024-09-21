/*
[STACK]. Bài 4. Thêm dấu ngoặc

ĐỀ: Cho xâu kí tự chỉ bao gồm dấu đóng mở ngoặc tròn. Hãy tìm số lượng dấu đóng mở ngoặc cần thêm tối
thiểu để tạo thành một xâu cân bằng, bạn có thể thêm các kí tự đóng mở ngoặc vào bất kì vị trí nào của xâu.

*/
#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    int cnt = 0;
    stack<char> st;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else {
            if (!st.empty()) 
                st.pop();
            else cnt++;
        }
    }
    int res = cnt + st.size();
    return res;
}
int main()
{
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}