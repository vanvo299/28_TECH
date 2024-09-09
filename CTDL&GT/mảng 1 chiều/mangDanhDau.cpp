// MẢNG ĐÁNH DẤU
// Nhược điểm: không thể đánh dấu được giá trị âm (tức không thể sử dụng nếu mảng có giá trị âm hoặc giá trị trong mảng có giá trị quá lớn)
// Ưu điểm: tối ưu thời gian rất nhanh

// Chỉ dùng mảng đánh dấu khi dữ liệu không âm và <= 10^7

// Bài 8: Liệt kê các giá trị khác nhau
/*
Cho mảng số nguyên A[] gồm N phần tử, hãy liệt kê các giá trị khác nhau trong mảng theo thứ tự xuất hiện,
mỗi giá trị chỉ liệt kê 1 lần. Ở thời điểm hiện tại các bạn có thể for trâu để giải bài này, sau này sẽ dùng cách tối ưu hơn.
*/

// Làm bằng phương pháp mảng đánh dấu
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int cnt[1000001]; // mang danh dau (tat ca phan tu trong mang bang 0)
int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    
    for (int i = 0; i < n; i++) {
        cnt[a[i]] = 1;
    }
    int dem = 0;
    for (int i = 0; i < 1000000; i++) {
        if (cnt[i] == 1) {
            cout << i << " ";
        }
    }

    return 0;
}