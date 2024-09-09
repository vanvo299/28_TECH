/*
[Two Pointer]. Bài 10. TwoSum

Đề: Cho mảng A[] có N phần tử và số nguyên K, hãy kiểm tra xem trong mảng có 2 phần tử A[i], A[j] với i khác j
và A[i] + A[j] = K hay không ? Bài này có thể giải theo 3 cách: Binary search, Hai con trỏ, map

*/

// Cách dùng hai con trỏ

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

    int left = 0, right = n - 1;
    while(left < right) {
        if (a[left] + a[right] == k) {
            cout << "YES\n";
            return 0;
        }
        else if (a[left] + a[right] < k) {
            ++left;
        } else --right;
    }
        cout << "NO\n";
    return 0;
}