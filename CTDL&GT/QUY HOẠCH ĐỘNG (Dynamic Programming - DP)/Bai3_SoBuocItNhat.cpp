/*
[DP]. Bài 3. Số bước ít nhất

Đề: Cho mảng A[] gồm N số nguyên. Nhiệm vụ của bạn là sắp xếp mảng số với số lượng
bước là ít nhất. Tại mỗi bước, bạn chỉ được phép chèn phần tử bất kì của mảng vào vị trí
bất kì trong mảng. Ví dụ a[] = {2, 3, 5, 1, 4, 7, 6} sẽ cho ta số phép chèn ít nhất là 3 bằng
cách lấy số 1 chèn trước số 2, 4 chèn trước số 5, lấy số 6 chèn trước số 7 ta nhận
được mảng sắp xếp
*/

/*
- Cách làm: Sô phần tử di chuyển ít nhất <=> số phần tử ở lại là nhiều nhất
=> các phần tử ở lại là dãy con tăng dần dài nhất
*/
#include <bits/stdc++.h>
using namespace std;

int F[10001];

int main()
{
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >>  a[i];
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        F[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (a[j] < a[i]) {
                F[i] = max(F[i], F[j] + 1);
            }
        }
        res = max(res, F[i]);
    }
    cout << n - res << endl;
    return 0;
}