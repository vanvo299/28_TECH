/*
[Sắp xếp - Tìm kiếm]. Bài 27. Số nhỏ nhất lớn hơn A[i]

Đề: Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là tìm giá trị nhỏ nhất (phải thuộc mảng A[]) lớn hơn A[i] (i = 0,
1, 2,..., n - 1). Đưa ra '_' nếu A[i] không có phần tử lớn hơn nó. Ví dụ với mảng A[] = {13, 6, 7, 12} ta có kết quae là 
{_, 7, 12, 13}.

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];

    for (int &x : a) cin >> x;
    int tmp[n];
    for (int i = 0 ; i < n; i++) {
        tmp[i] = a[i];
    }
    sort(tmp, tmp + n);
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(tmp, tmp + n, a[i]);
        if (it == tmp + n) {
            cout << '_' << ' ';
        }else cout << *it << ' ';
    }
    return 0;
} 