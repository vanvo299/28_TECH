/*
[Xâu kí tự]. Bài 9. Đếm số lượng từ trong xâu.

Đề: Cho một xâu kí tự S bao gồm các chữ cái và dấu cách, một từ được định nghĩa là các kí tự liên tiếp khong chứa
dấu cách, hãy đếm số lượng từ xuất hiện trong xâu S.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    // Cách 1: dùng stringstream 

    getline(cin, s);
    stringstream ss(s);
    string word;
    int count = 0;
    while(ss >> word) {
        ++count;
    }
    cout << count << endl;

    // Cách 2: Dùng biến đếm

    // int count = 0;
    // while (cin >> s) {
    //     ++count;
    // }
    // cout << count << endl;
    return 0;
}