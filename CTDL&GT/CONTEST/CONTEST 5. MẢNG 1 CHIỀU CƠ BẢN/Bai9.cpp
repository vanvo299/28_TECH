// [MẢNG 1 CHIỀU CƠ BẢN]. BÀI 9: TẦN SUẤT
/*
Cho mảng số nguyên A[] gồm N phần tử, hãy liệt kê các giá trị xuất hiện trong mảng kèm 
theo tần suất tương ứng, mỗi giá trị chỉ liệt kê một lần theo thứ tự xuất hiện
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
        cnt[a[i]]++;
    }

    for (int i = 0; i < 1000000; i++) {
        if (cnt[i]) {
            cout << i << " " << cnt[i] << "\n";
        }
    }
    return 0;
}
