/*
[Xâu kí tự cơ bản]. Bài 19. Đếm số lượng từ khác nhau trong xâu.

Đề: Cho xâu kí tự S gồm các từ được phân tách nhau bởi một vài dấu cách. Thực hiện đếm số lượng các từ khác
nhau trong xâu mà không phân biệt hoa thường, ví dụ "28TecH" được coi là giống với từ "28teCH" 

*/

#include <iostream>
#include <string>
#include <set>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> a;
    set<string> se;
    string s;
    while(cin >> s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        se.insert(s);
    }
    cout << se.size() << endl;
    
    return 0;
}