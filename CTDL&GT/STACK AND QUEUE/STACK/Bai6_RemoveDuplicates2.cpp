/*
[STACK]. Bài 6. Remove Duplicates 2

ĐỀ: Cho một xâu kí tự S chỉ bao gồm kí tự in thường, nhiệm vụ của bạn là xóa k kí tự liền kề
giống nhau khỏi xâu. Ví dụ xâu aaabbbcccedddeeu sau khi xóa 3 kí tự liền kề giống nhau 
khỏi xâu S sẽ trở thành u

*/
#include <bits/stdc++.h>
using namespace std;

string solve(string s, int k)
{
    stack<pair<char, int>> st;

    for (char c : s) {
        // Nếu stack không rống và ký tự hiện tại giống với kí tự trên đỉnh stack
        if (!st.empty() && st.top().first == c) {
            st.top().second++; // tăng số lượng kí tự liền kề giống nhau
            if (st.top().second == k) {
                st.pop(); // Nếu số lượng bằng k, pop khỏi stack
            }
        } else {
            st.push({c, 1}); // Thêm kí tự mới vào stack
        }
    }
    string res = "";
    while(!st.empty()) {
        auto it = st.top(); st.pop();
        for(int i = 0; i < it.second; i++) {
            res += it.first;
        }   
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    string s; 
    cin >> s;
    int k; 
    cin >> k;
    string res = solve(s, k);
    if (res.size() == 0) {
        cout << "EMPTY\n";
    } else cout << res;
    return 0;
}