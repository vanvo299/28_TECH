// [MẢNG 1 CHIỀU CƠ BẢN]. BÀI 8: LIỆT KÊ
/*
Cho mảng số nguyên A[] gồm N phần tử, hãy liệt kê các giá trị khác nhau trong mảng theo
thứ tự xuất hiện, mỗi giá trị chỉ liệt kê 1 lần. Ở thời điểm hiện tại các bạn có thể dùng 
for trâu để giải bài này, sau này sẽ dùng cách tối ưu hơn
*/
#include <iostream>
#include <cmath>
using namespace std;

int cnt[1000001];
int main()
{
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;

    for (int i = 0; i < n; i++) {
         cnt[a[i]] = 1;
    }

    for (int i = 0; i < 1000000; i++) {
        if (cnt[i]) {
            cout << i << ' ';
        }
    }
   
    return 0;
}
