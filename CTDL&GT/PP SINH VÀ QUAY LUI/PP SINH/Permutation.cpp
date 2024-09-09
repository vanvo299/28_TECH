/*
- Trong C++ cũng cung cấp 2 hàm next_permutation để sinh ra cấu hình kế tiếp 
và prev_permutation để sinh ra cấu hình liền trước. Các bạn có thể sử dụng nó và
kết hợp với mảng hoặc vector để sinh hoán vị.

- Hàm next_permutation và prev_permutation áp dụng với mảng, đối với vector và string các bạn
thay bằng iterator begin và end 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // next_permutation

    int a[] = {1, 2, 6, 9, 8, 7, 5, 4, 3};
    // next_permutation(a, a + 9);
    cout << next_permutation(a, a + 9) << endl; // co the tra ve true or false
    for (int &x :a) cout << x << ' ';

    // sinh hoan vi
    int x[] = {1, 2, 3, 4};
    do {
        for (int i = 0; i < 4; i++) {
            cout << x[i] << ' ';
        }
        cout << endl;
    } while(next_permutation(x, x + 4));

    cout << endl;

    // dung voi string (vecto tuong tu)
    string s = "126987543";
    cout << next_permutation(s.begin(), s.end()) << endl;
    cout << s << endl;
    // prev_permutation dùng tương tự như next_permutation


    return 0;
}