/*
[Two Pointer]. Bài 2. 28Tech_Smaller

Đề: Cho 2 mảng A[] và B[] có N và M phần tử đã được sắp xếp theo thứ tự tăng dần, nhiệm vụ của bạn là đối với 
mỗi phần tử trong mảng B[] hãy đếm xem trong mảng A[] có bao nhiêu phần tử nhỏ hơn nó.


*/
#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    int n, m; cin >> n >> m;
    int a[n], b[m];

    for (int &x : a) cin >> x;
    for (int &y : b) cin >> y;

    int i = 0, j = 0;

    while(i < n && j < m) {
        if (a[i] < b[j]) {
            ++i;
        }
        else {
            cout << i << " ";
            ++j;
        }
    }

    while(j < m) {
        cout << n << " ";
        ++j;
    } 
    return 0;
}