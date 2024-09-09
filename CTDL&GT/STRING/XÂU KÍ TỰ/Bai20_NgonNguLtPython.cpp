/*
[Xâu kí tự]. Bài 20. Ngôn ngữ lập trình Python.

Đề: Trong giờ học lập trình Python, thầy giáo có đưa ra một bài toán cho Tèo, bài toán như sau "Cho một
xâu kí tựu S. Tèo hãy xác định xem liệu rằng có thể xóa đi bất kì một kí tự nào trong xâu S ở một vị trí bất kì và
xâu S trở thành từ "python" được hay không ? Biết rằng Tèo có thể xóa bất kì một kí tự nào nhưng không thể 
hoán đổi vị trí các kí tự trong xâu S ban đầu". Hiện nay vì Tèo đang bận gói bánh chưng phụ thầy mẹ nên nhờ 
bạn giải giúp.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    string t = "Python";
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    transform(t.begin(), t.end(), t.begin(), ::tolower);

    int idx = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[idx]) {
            ++idx;
        }
        if (idx == t.size()) {
            cout << "YES";
            return 0;
        }
   }
   cout << "NO";
    return 0;
}