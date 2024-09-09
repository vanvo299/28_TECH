// [MẢNG 1 CHIỀU]. BÀI 9. Đếm tần suất
/*
Cho mảng các số nguyên không âm gồm n phần tử, thực hiên đếm tần suất xuất hiện của n phần tử 
và in theo mẫu.

**Output format: In ra tần suất xuất hiện theo thứ tự từ nhỏ tới sau đó bỏ trống 1 dòng 
và in ra tần suất xuất hiện của các phần tử theo thứ tự xuất hiện trong mảng (mỗi giá trị chỉ liệt kê 1 lần).
*/
#include <bits/stdc++.h>
using namespace std;

int cnt[10001];
int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    for (int i = 0; i < n; i++) cnt[a[i]]++;

    for (int i = 0; i < 10001; i++) {
        if (cnt[i]) {
            cout << i << " " << cnt[i] << "\n";
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] > 0) {
            cout << a[i] << " " << cnt[a[i]] << endl;
            cnt[a[i]] = 0;
        }
    }
    return 0;
}