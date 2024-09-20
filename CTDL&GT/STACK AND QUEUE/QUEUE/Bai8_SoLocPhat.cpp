/*
[QUEUE]. Bài 8. Số lộc phát

ĐỀ: Một số được gọi là số lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá
N chữ số
*/
#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    vector<string> res;
    queue<string> Q;
    Q.push("6");
    Q.push("8");

    // Tạo các số lộc phát cho đến khi độ dài tối đa là n
    while (!Q.empty()) {
        string tmp = Q.front(); Q.pop();
        
        // Thêm số vào kết quả nếu độ dài nhỏ hơn hoặc bằng n
        if (tmp.size() <= n) {
            res.push_back(tmp);
            // Tiếp tục tạo số mới bằng cách thêm 6 hoặc 8
            Q.push(tmp + "6");
            Q.push(tmp + "8");
        }
    }

    // In ra kết quả
    for (const string& x : res) {
        cout << x << ' ';
    }
}

int main() {
    int t; 
    cin >> t; // Số lượng test case
    while (t--) {
        int n; 
        cin >> n; // Độ dài tối đa của số lộc phát
        solve(n);
        cout << endl;
    }
    return 0;
}
