/*
[Chia và trị]. Bài 10. Đếm số 0

Đề: Cho mảng A[] gồm N phần tử chỉ bao gồm các số 0 và 1. Các số 0 được đặt trước các số 1.
Hãy đếm các số 0 với thời gian log(N)
*/
#include <bits/stdc++.h>
using namespace std;

int countNumber0(int a[], int n)
{
    int left  = 0, right = n - 1, res = -1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == 1) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}
int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    cout << countNumber0(a, n);
    return 0;
}