/*
[Quay lui - Nhánh cận]. Bài 24. Letter Case

Đề: Cho xâu kí tự S chỉ bao gồm chữ cái và chữ số, bạn có thể thay đổi các chữ cái trong xâu thành kiểu in hoa
hoặc in thường tương ứng của nó nhưng không được thay đổi vị trí ban đầu. Bạn hãy liệt kê mọi xâu khác 
nhau có thể tạo thành bằng cách trên và liệt kê theo thứ tự tăng dần.
*/
#include <bits/stdc++.h>
using namespace std;

string s, tmp = "";
set<string> res; 

void Try(int index)
{
    for (char x : {tolower(s[index]), toupper(s[index])}) {
        tmp += x;
        if (tmp.size() == s.size()) {
            res.insert(tmp);
        } else {
            Try(index + 1);
        }
        // backtrack
        tmp.pop_back();
    }
}
int main()
{
    cin >> s;
    Try(0);
    for (string x : res) {
        cout << x << endl;
    }
    return 0;
}