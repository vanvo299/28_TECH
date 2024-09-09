/*
[Xâu kí tự]. Bài 8. Xâu Pangram 1.

Đề: Xâu Pangram là xâu có chứa đầy đủ các kí tự từ A tới Z không phân biệt chữ hoa chữ thường. Nhập vào xâu S
và kiểm tra xem xâu S có phải là xâu pangram hay không ?

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        transform(S.begin(), S.end(), S.begin(), ::tolower);
    }
    int cnt[256] = {0};
    for (char x : S) {
        cnt[x] = 1;
    }
    int check = 0;
    for (int i = 97; i <= 122; i++) {
        if (cnt[i] == 0) {
            check = 1;
        }
    }
    if (check) {
        cout << "NO";
    } else cout << "YES";
    return 0;
}