/*
7. Lower_Bound
- Cú pháp: lower_bound(first_iter, last_iter, X);
- Sử dụng Lower_bound:
+ Lower_bound là một hàm tương tự như biến thể của tìm kiếm nhị phân, nó có thể
áp dụng cho mảng, vector, set, map. Với điều kiện là Mảng, vector đã được sắp xếp tăng dần
+ Tương tự như hàm sort, lower_bound cũng trả về iterator chứ không trả về giá trị
+ Nó trả về vị trí đầu tiên của phần tử lớn hơn hoặc bằng X, nếu trong mảng, vector bạn tìm kiếm
không có phần tử lớn hơn hoặc bằng X (tất cả đều nhỏ hơn X) thì lower_bound trả về last_iter

8. Upper bound
- Cú pháp: upper_bound(first_iter, last_iter, X);
- Điều kiện sử dụng: Mảng, vector, đã được sắp xếp tăng dần
- Upper_bound trả về vị trí của phần tử lớn X, nếu trong mảng, vector bạn tìm kiếm
không có phần tử lớn hơn X (Tất cả đêù nhỏ hơn hoặc bằng X) thì upper_bound trả về last_iter),
*NOTE: Upper_bound về cách dùng thì giống với lower_bound, chỉ khác chỗ upper_bound trả về phần tử lớn hơn X, còn lower_bound trả về 
phần tử lớn hơn hoặc bằng X.

*/
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // Use with array

    // int n; cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }
    // sort(a, a + n);
    // auto it = lower_bound(a, a + n, 2);
    // cout << *it << endl;
    // cout << (it - a) << endl;

    // // co the ap dung lower found de tim vi tri dau tien xuat hien cua X
    // if (*it != 2) {
    //     cout << "NOT FOUND\n";
    // } else cout << "FOUND\n";
    // // auto it1 = lower_bound(a, a + n, 7);
    // // cout << *it1 << endl; // khong tim duoc nen tra ve gia tri rac
    // // cout << (it1 - a) << endl; // tra ve vi tri n

    // Use with set, multiset....
    multiset<int> ms;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ms.insert(x);
    }
    // auto it = lower_bound(ms.begin(), ms.end(), 2);
    auto it = ms.lower_bound(2); // nhanh hon
    auto it = ms.lower_bound(10); // khi ko tim duoc thi return ve ms.end()
    cout << *it << endl;
    return 0;
}