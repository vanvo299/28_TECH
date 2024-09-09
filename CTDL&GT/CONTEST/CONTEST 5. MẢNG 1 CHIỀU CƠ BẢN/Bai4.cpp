// [MẢNG 1 CHIỀU CƠ BẢN]. BÀI 4: LỚN HƠN, NHỎ HƠN
/*
Cho mảng số nguyên A[] gồm n phần tử và số nguyên x, hãy đếm xem trong mảng có bao
nhiêu số lớn hơn x và bao nhiêu số nhỏ hơn x
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, x; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    cin >> x;
    
    int count_lonHonX = 0, count_nhoHonX = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < x) ++count_nhoHonX;
        if (a[i] > x) ++count_lonHonX;
    }

    cout << count_nhoHonX << "\n";
    cout << count_lonHonX << "\n";
    return 0;
}
