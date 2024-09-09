/*
[Xâu kí tự]. Bài 6. Ký tự xuất hiện ở 2 xâu 2.

Đề: Cho 2 xâu kí tự S1 và S2 chỉ bao gồm chữ cái in hoa và in thường, hãy tìm các kí tự xuất hiện trong xâu S1 mà
không xuất hiện trong xâu S2, và các kí tự chỉ xuất hiện trong xâu S2 mà không xuất hiện trong xâu S1. Các kí 
tự được in ra theo thứ tự từ điển và chỉ liệt kê mỗi ký tự 1 lần.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S1, S2;
    cin >> S1 >> S2;
    int cnt1[256] = {0}, cnt2[256] = {0};
    for (char x : S1) {
        cnt1[x] = 1;
    }
    for (char x : S2) {
        cnt2[x] = 1;
    }

    for (int i = 0; i < 256; i++) {
        if (cnt1[i] && cnt2[i] == 0) {
            cout << (char) i;
        }
    }
    cout << endl;
    for (int i = 0; i < 256; i++) {
        if (cnt2[i] && cnt1[i] == 0) {
            cout << (char) i;
        }
    }
    return 0;
}