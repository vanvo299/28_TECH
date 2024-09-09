/*
[Xâu kí tự]. Bài 5. Ký tự xuất hiện ở cả 2 xâu.

Đề: Cho 2 xâu kí tự S1 và S2, hãy in ra các kí tự xuất hiện ở cả 2 xâu theo thứ tự từ điển,  chú ý mỗi kí tự chỉ liệt kê
một lần. Sau đó tiếp tục liệt kê các kí tự tự xuất hiện ở 1 trong 2 xâu theo thứ tự từ điển.

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t; cin >> s >> t;
    int cnt1[256] = {0}, cnt2[256] = {0};
    for (char x : s) {
        cnt1[x] = 1;
    }
    for (char x : t) {
        cnt2[x] = 1;
    }

    for (int i = 0; i < 256; i++) {
        if (cnt1[i] && cnt2[i]) {
            cout << (char) i;
        }
    }
    cout << endl;
    for (int i = 0; i < 256; i++) {
        if (cnt1[i] || cnt2[i]) {
            cout << (char) i;
        }
    }

    return 0;
}