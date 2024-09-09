/*
[Two Pointer]. Bài 6. 28Tech_SegCount1

Đề: Cho mảng A[] gồm N phần tử và số nguyên S, nhiệm vụ của bạn là đếm xem có bao nhiêu mảng con các
phần tử liên tiếp trong mảng mà tổng không vượt quá S.

*/

#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    int n, s; cin >> n >> s;
    int a[n];
    for (int &x : a) cin >> x;

    int left = 0, right = 0;
    ll sum = 0, res = 0;

    for (right = 0; right < n; right++) {
        sum += a[right];
        // cap nhat doan left => right : OK
        // sum <= s
        while(sum > s) {
            sum -= a[left];
            ++left;
        }
        res += right - left + 1; // cap nhat so mang con tu left => right
    }
    cout << res << endl;
    return 0;
}