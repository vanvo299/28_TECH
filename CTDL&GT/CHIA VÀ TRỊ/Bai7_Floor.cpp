/*
[Chia và trị]. Bài 7. Floor

Đề: Cho mảng đã được sắp xếp A[] gồm N phần tử không có hai phần tử giống nhau và số X. Nhiệm vụ
của bạn là tìm floor(x). Trong đó, K = floor(x) là phần tử lớn nhất trong mảng A[] nhỏ hơn hoặc bằng X.
*/
#include <bits/stdc++.h>
using namespace std;

int floor(int a[], int n, int x)
{
    int left = 0, right = n - 1, res = -1;
    while(left < right) {
        int mid = (left + right) / 2;
        if (a[mid] <= x) {
            res = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return res;
}
int main()
{
    int n, x; cin >> n >> x;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a + n);
    cout << a[floor(a, n, x)];
    return 0;
}