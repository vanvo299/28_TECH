/*
[Two Pointer]. Bài 13. Xâu 28.

Đề: 28Tech rất yêu thích con số 28 vì thế anh ta có bài toán sau và nhờ bạn tìm lời giải. Cho một xâu kí tự S chỉ bao
gồm kí tự 2 và kí tự 8, bạn hãy tìm xâu con liên tiếp có độ dài lớn nhất mà trong đó chứa nhiều nhất X kí tự 2 
và Y kí tự 8.

*/

#include <iostream>
#include <string>

using namespace std;

using ll = long long;

int main()
{
    string s; cin >> s;
    int x, y; cin >> x >> y;
    int count2 = 0, count8 = 0, res = 0;
    int left = 0;

    for (int right = 0; right < s.size(); right++) {
        if (s[left] == '2') ++count2;
        else ++count8;

        while(count2 > x || count8 > y) {
            if (s[left] == '2') --count2;
            else --count8;
            ++left;
        } 
        res = count2 + count8;
    }
    cout << res << endl;
    return 0;
}