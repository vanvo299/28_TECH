// [MẢNG 1 CHIỀU]. BÀI 6. Đếm cặp số nguyên tố cùng nhau
/*
Cho một dãy số nguyên dương có n phần tử. Hãy đếm các cặp số nguyên tố cùng nhau

**Cặp nguyên tố cùng nhau là 2 số có UCLN bằng 1
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n; cin >> n; 
    int a[n];
    for (int &x : a) cin >> x;
    int count = 0;
    for (int i = 0 ; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (__gcd(a[i], a[j]) == 1) {
                ++count;
                // cout << a[i] << " " << a[j] << endl;
            } 
        }
    }
    cout << count << endl;
    return 0;
}