/*
[Two Pointer]. Bài 12. Sum of four values.

Đề: Cho mảng A[] gồm N phần tử và số nguyên K, hãy kiểm tra xem trong mảng có 4 phần tử A[i], A[j], A[k], A[l] với
i, j, k, l khác nhau và A[i] + A[j] + A[k] + A[l] = K hay không ?
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, K; cin >> n >> K;
    int a[n];
    for (int &x : a) cin >> x;

    sort(a, a + n);
    int left = 2, right = n - 1;

    while(left < right) {
        if (a[left] + a[right] == K - a[0] - a[1]) {
            cout << "YES\n";
            return 0;
        } 
        else if (a[left] + a[right] < K - a[0] - a[1]) ++left;
        else --right;
    }
    cout << "NO\n";
    return 0;
}