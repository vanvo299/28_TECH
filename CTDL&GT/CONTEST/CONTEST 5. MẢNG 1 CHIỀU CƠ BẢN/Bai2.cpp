// [MẢNG 1 CHIỀU CƠ BẢN]. BÀI 2: TRUNG BÌNH CỘNG NGUYÊN TỐ
/*
Cho mảng số nguyên A[] gồm N phần tử. Nhiệm vụ của bạn là tính trung bình cộng của các
số nguyên tố trong dãy. Dữ liệu đảm bảo có ít nhất 1 phần tử là số nguyên tố trong dãy
*/ 
#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
bool nt(ll n)
{
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    } return n > 1;
}
int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    int trungBinhCong = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nt(a[i])) {
            ++cnt;
            trungBinhCong += a[i];
        }
    }
    cout << "Trung binh cong cua cac so nguyen to: " << trungBinhCong / cnt << "\n";
    return 0;
}
