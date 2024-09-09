/*
[Two Pointer]. Bài 11. Sum of three values.

Đề: Cho mảng A[] gồm N phần tử và số nguyên K, hãy kiểm tra xem trong mảng có 3 phần tử A[i], A[j], A[k] với i, j, k
khác nhau và A[i] + A[j] + A[k] = K hay không ?

*/

#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int main()
{
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;

    sort(a, a + n);
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        while(left < right) {
            if (a[left] + a[right] == k - a[i]) {
                cout << "YES\n";
                return 0;
            }
            else if (a[left] + a[right] < k - a[i]) ++left;
            else --right;
        }
    }
    cout << "NO" << endl;
    return 0;
}