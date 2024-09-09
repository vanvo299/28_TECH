/*
[Tham Lam]. Maximum Perimeter Triangle

Đề: Given an array of stick lengths, use 3 of them to construct a non-degenerate  triangle with the maximum
possible perimeter. Return an array of the lengths of its sides as 3 integers in non - decreasing order.

If there are several valid triangles having the maximum perimeter:
1. Choose the one with the longest maximum side
2. If more than one has that maximum, choose from them the one with the longest minimum side
3. If more than one has that maximum as well, print any one them.

If no non-degenerate triangles exists, return -1

- Dịch:
Cho một mảng độ dài các thanh, hãy sử dụng 3 thanh trong số đó để tạo một tam giác không suy biến có chu vi lớn nhất có thể. 
Trả về một mảng độ dài của các cạnh của tam giác dưới dạng 3 số nguyên theo thứ tự không giảm.

Nếu có nhiều tam giác hợp lệ có chu vi lớn nhất:

1. Chọn tam giác có cạnh dài nhất lớn nhất.
2. Nếu có nhiều tam giác có cạnh dài nhất bằng nhau, chọn tam giác trong số đó có cạnh ngắn nhất dài nhất.
3. Nếu có nhiều tam giác có cạnh ngắn nhất dài nhất bằng nhau, in ra bất kỳ tam giác nào trong số đó.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(int a, int b, int c)
{
    return a + b > c && a + c > b && b + c > a;
}

int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a + n);

    ll maxPerimeter = 0;
    int x = -1, y = -1, z = -1;
    
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (check(a[i], a[j], a[k])) {
                ll tmp = a[i] + a[j] + a[k]; // lưu tam giác hiện tại
                if (tmp > maxPerimeter) {
                    maxPerimeter = tmp;
                    x = a[i]; y = a[j]; z = a[k];
                } 
                else if (tmp == maxPerimeter) {
                    if (z < a[k]) {
                        x = a[i]; y = a[j]; z = a[k];
                    }
                    else if (z == a[k] && x < a[i]) {
                        x = a[i]; y = a[j]; z = a[k];
                    }
                }
                }
            }
        }
    }
    if (x == -1) cout << "-1" << endl;
    else {
        cout << x << ' ' << y << ' ' << z << endl;
    }

    return 0;
}