// [MẢNG 1 CHIỀU CƠ BẢN]. BÀI 10: CÂN BẰNG NGUYÊN TỐ
/*
Cho mảng số nguyên A[] gồm N phần tử, hãy liệt kê các chỉ số i trong mảng thỏa mãn: 
Tổng các phần tử bên trái i và tổng các phần tử bên phải i là các số nguyên tố
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
    // int n; cin >> n;
    // int a[n];
    // for(int &x : a) cin >> x;

    // for (int i = 1; i < n - 1; i++) {
    // int sum_left = 0, sum_right = 0;
    //     for (int j = 0; j < i; j++) sum_left += a[j];
    //     for (int j = i + 1; j < n; j++) sum_right += a[j];
    //     if (nt(sum_left) && nt(sum_right))
    //     cout << i << ' ';
    // }

    // CÁCH KHÁC: Có độ phức tạp tối ưu hơn
    int n, sum = 0;; cin >> n;
    int a[n];
    for(int &x : a) {
        cin >> x;
        sum += x;
    }

    int sum_left = a[0];
    for (int i = 1; i < n; i++) {
        int sum_right = sum - sum_left - a[i];
        if (nt(sum_left) && nt(sum_right)) 
        cout << i <<' ';
        sum_left += a[i];
        
    }
    return 0;
}
