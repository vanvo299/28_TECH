//// [SET MAP]. Bài 7. Số lượng từ khác nhau trong xâu
/*
Cho một xâu kí tự S chỉ bao gồm các kí tự là chữ cái và dấu cách. Hãy đếm số lượng từ khác nhau trong xâu S
và in ra từ có thứ tự từ điển nhỏ nhất, lớn nhất trong xâu S

Gợi ý: Dùng set<string>

// Cú pháp để đọc hết mọi từ trong input:
string s;
while(cin >> s) {
    // xử lý s
}
*/
#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;
int main()
{ 
    set<string> se;
    string s;
    while(cin >> s) {
        se.insert(s);
    }
    cout << se.size() << endl;
    cout << *se.begin() << " " << *se.rbegin() << endl;
    return 0;
}
