// [SET MAP]. Bài 3. Phần tử riêng biệt
/*
Cho dãy số A[] gồm có N phần tử, hãy liệt kê các giá trị xuất hiện trong dãy theo thứ tự xuất hiện, 
mỗi giá trị chỉ liệt kê một lần

Gợi ý: Dùng set để lưu các phần tử đã được in ra trước đó, gặp phần tử a[i] thì kiểm tra nhanh trong set có giá trị 
a[i] hay chưa để in ra
*/
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    set<int> se;
    for (int i = 0; i < n; i++) {
        if (se.find(a[i]) == se.end()) {
            cout << a[i] << " ";
        }
        se.insert(a[i]);
    }
    return 0;
}