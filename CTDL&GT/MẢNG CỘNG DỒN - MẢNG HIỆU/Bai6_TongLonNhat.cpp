/*
[Mảng cộng dồn - Mảng hiệu]. Bài 6. Tổng lớn nhất

Đề: Tèo đang làm các bài toán với truy vấn tổng trên đoạn, mỗi truy vấn yêu cầu các bạn tính tổng phần tử từ
chỉ số L tới chỉ số R, tuy nhiên bài toán này đã quá quen thuộc và dễ dàng có thể dùng mảng cộng dồn để giải
quyết vì Tèo đưa ra thêm 1 yêu cầu cho bài toán.

Cho trước các truy vấn từ chỉ số L tới chỉ số R, bây giờ bạn đã biết trước tất cả Q truy vấn bạn được phép
thay đổi thứ tự các phần tử trong mảng 1 lần duy nhất trước khi thực hiện các truy vấn. Hãy thay đổi mảng 
sao cho tổng các truy vấn trên đoạn đạt được giá trị lớn nhất. Một cách rõ ràng hơn, bạn hãy tính tổng mọi
mảng con trong từng truy vấn sau đó cộng lại để đạt được giá trị lớn nhất.
*/
/*
Input: 
6 2
5 2 5 3 5 1
2 5    
2 4

** (2, 4) : 2 (những số lớn nhất nằm trong đoạn này) (5 : 5 : 5)
** (4, 5) : 1 (những số cũng lớn mà lớn sau thì nằm trong này (là bé hơn những số nằm trong khoảng đầu)) (3)

=> A : 1 5 5 5 3 2
sau khi sort: 5 5 5 3 2 1
*/
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int d[n + 5] = {0};
    while(q--) {
        int l, r; cin >> l >> r;
        --l; --r;
        d[l] += 1;
        d[r + 1] -= 1;
    }

    int F[n];
    F[0] = d[0];
    for (int i = 1; i < n; i++) {
        F[i] = F[i - 1] + d[i];
    }
    for (int i = 0; i < n; i++) {
        cout << F[i] << " ";
    }

    sort(F, F + n, greater<int>());
    sort(a, a + n, greater<int>());

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i] * F[i];
    }

    cout << endl << res << endl;
    return 0;
}