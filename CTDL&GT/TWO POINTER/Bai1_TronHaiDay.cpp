/*
[Two pointer]. Bài 1. Trộn 2 dãy

Đề: Cho 2 mảng A[] và B[] có N và M phần tử đã được sắp xếp theo thứ tự tăng dần, nhiệm vụ của bạn là trộn 2
mảng này thành một mảng và sắp xếp theo thứ tự tăng dần. Độ phức tạp mong muốn là tuyến tính.
*/

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int i = 0, j = 0;
    while(i < n && j < m) {
        if (a[i] <= b[j]) {
            cout << a[i] << " ";
            ++i;
        }
        else {
            cout << b[j] << " ";
            ++j;
        }
    }

    while(i < n) {
        cout << a[i] << " ";
        ++i;
    }

    while(j < m) {
        cout << b[j] << " ";
        ++j;
    }

    return 0;
}