// [MẢNG 1 CHIỀU]. BÀI 8. Trộn 2 dãy đã sắp xếp
/*
Cho 2 mảng đã được sắp xếp tăng dần và thực hiện trộn 2 dãy thành 1 dãy đã được sắp xếp
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) cout << a[i++] << " ";
        else cout << b[j++] << " ";
    }

    while (i < n) cout << a[i++] << " ";
    while (j < m) cout << b[j++] << " ";
    return 0;
}