// [MẢNG 1 CHIỀU CƠ BẢN]. BÀI 1: Đếm chẵn lẻ, tổng chẵn lẻ
/*
Cho mảng số nguyên A[] gồm n phần tử, nhiệm vụ của bạn là đếm xem trong mảng có bao nhiêu số chẵn, bao
nhiêu số lẻ, tổng các phần tử là số chẵn, tổng các phần tử là số lẻ.
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    // đếm số chẵn, tổng số chẵn
    int count_chan = 0, sum_chan = 0, count_le = 0, sum_le = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            ++count_chan;
            sum_chan += a[i];
        } else {
            ++count_le;
            sum_le += a[i];
        }
    }

    cout << "So luong so chan co trong mang: " << count_chan << "\n";
    cout << "So luong so le co trong mang: " << count_le << "\n";
    cout << "Tong cac phan tu chan trong mang: " << sum_chan << "\n";
    cout << "Tong cac phan tu le trong mang: " << sum_le << "\n";
    
    return 0;
}