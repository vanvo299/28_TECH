// [MẢNG 1 CHIỀU CƠ BẢN]. BÀI 12: VỊ TRÍ SỐ LỚN NHẤT, NHỎ NHẤT
/*
Cho mảng số nguyên A[] gồm N phần tử, hãy tìm vị trí (bắt đầu từ 0) cuối cùng của giá trị
nhỏ nhất trong mảng và vị trí đầu tiên của giá trị lớn nhất trong mảng. Tức là nếu có nhiều 
số có cùng giá trị nhỏ nhất bạn phải in ra vị trí cuối cùng và có nhiều số có cùng giá trị lớn
nhất trong mảng bạn phải in ra vị trí đầu tiên lớn nhất đó.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;

    int max = 1e-6, min = 1e9, index_min, index_max;
    for (int i = 0; i < n; i++) {
        if (a[i] <= min) {
            min = a[i];
            index_min = i;
        }
        if (a[i] > max) {
            max = a[i];
            index_max = i;
        }
    }
    cout << min << " " << max << "\n";
    cout << index_min << ' ' << index_max << "\n";
    return 0;
}
