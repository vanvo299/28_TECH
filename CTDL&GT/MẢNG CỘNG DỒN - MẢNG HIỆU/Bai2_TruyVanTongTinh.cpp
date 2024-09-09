/*
[Mảng cộng dồn - Mảng hiệu]. Bài 2: Truy vấn tổng tĩnh

Đề: Cho mảng số nguyên A[] gồm N phần tử, có Q truy vấn, mỗi truy vấn là 2 số L, R, bạn hãy tính tổng các số từ
chỉ số L tới chỉ số R của mảng
*/

// Dung mang cong don tren mang 1 chieu
#include <iostream>
using namespace std;

using ll = long long;
int main()
{
    int n, q;
    cin >> n >> q;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    ll pre[n];
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            pre[i] = A[i];
        } 
        else {
            pre[i] = pre[i - 1] + A[i];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if ( l == 0) {
            cout << pre[r];
        } 
        else cout << pre[r] - pre[l - 1] << endl;
    }
    return 0;
}