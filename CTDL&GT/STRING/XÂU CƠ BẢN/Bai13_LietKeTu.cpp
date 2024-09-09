/*
[Xâu kí tự cơ bản]. Bài 13. Liệt Kê Từ

Đề: Cho một xâu S gồm nhiều phần tử, các từ được phân cách nhau bởi dấu cách hoặc các dấu '.', ',', '!', '?', hãy liệt kê các 
từ xuất hiện trong xâu, giữa các từ cách nhau một dấu cách, sau từ cuối cùng ko được được in thừa dấu cách.
*/

// Cách làm: chuyển các dấu . , ! ? thành dấu cách rồi dùng stringstream để tách
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?') {
            s[i] = ' ';
        }
    }
    stringstream ss(s);
    string word;
    while(ss >> word) {
        cout << word << " ";
    }
    return 0;
}