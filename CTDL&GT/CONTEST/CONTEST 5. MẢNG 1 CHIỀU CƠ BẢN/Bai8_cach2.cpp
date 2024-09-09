// Bài 8: Liệt kê các giá trị khác nhau
/*
Cho mảng số nguyên A[] gồm N phần tử, hãy liệt kê các giá trị khác nhau trong mảng theo thứ tự xuất hiện,
mỗi giá trị chỉ liệt kê 1 lần. Ở thời điểm hiện tại các bạn có thể for trâu để giải bài này, sau này sẽ dùng cách tối ưu hơn.qqqqqqq
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        bool check = true;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                check = false;
                break;
            }
        }
        if (check) cout << a[i] << " ";
    }
    return 0;
}