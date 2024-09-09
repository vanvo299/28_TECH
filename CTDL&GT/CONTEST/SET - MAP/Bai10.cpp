// [SET MAP]. Bài 10. INTERSECTION
/*
Cho mảng A[] và B[] lần lượt gồm N và M số nguyên, nhiệm vụ của bạn là tìm giao của 2 mảng này và int hep
thứ tự xuất hiện trong mảng A[].


Gợi ý: 
Cách 1: Dùng 2 set để lưu 2 mảng A, B sau đó duyệt 1 trong 2 mảng và tìm kiếm sự xuất hiện của phần tử
đang duyệt trong mảng còn lại

Cách 2: Dùng 1 map để đánh dấu, duyệt qua các phần tử trong mảng A[] và cho map của từng phần tửu trong 
mảng A[] = 1, duyệt qua mảng B[] thì kiểm tra nếu map của phần tử trong mảng B đã bằng 1 thì chuyển thành 2.
Cuối cùng duyệt map và in ra những phần tử được đánh dấu là 2.
*/
#include <iostream>
#include <set>
using namespace std;
int main()
{ 
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    set<int> seA(a, a + n);
    set<int> seB(b, b + m);

    for (int i = 0; i < n; i++) {
        if (seB.count(a[i])) {
            cout << a[i] << " ";
            seB.erase(a[i]);
        }
    }
    return 0;
}
