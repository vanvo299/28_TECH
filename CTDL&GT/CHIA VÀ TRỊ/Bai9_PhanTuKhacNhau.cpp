/*
[Chia và trị]. Bài 9. Phần tử khác nhau

Đề: Cho hai mảng đã được sắp xếp A[] và B[] gồm N và N - 1 phần tử. Các phần tử của mảng A[]
chỉ khác mảng B[] một phần tử duy nhất. Hãy tìm vị trí của phần tử khác nhau giữa A[] và B[]
*/
#include <bits/stdc++.h>
using namespace std;

int phanTuKhacNhau(int a[], int b[], int n)
{
    int left = 0, right = n - 2, res = -1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == b[mid]) {
            left = mid + 1;
        }
        else {
            res = mid;
            right = mid - 1;
        } 
            
    }
    return res;
}
int main()
{
    int n; cin >> n;
    int a[n], b[n - 1];
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    cout << phanTuKhacNhau(a, b, n) + 1;
    return 0;
}