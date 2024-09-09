// [MẢNG 1 CHIỀU CƠ BẢN]. BÀI 13: TÍNH TỔNG VÀ TÍCH CÁC PHẦN TỬ
/*
Cho mảng số nguyên A[] gồm N phần tử, hãy tính tổng, tích các phần tử trong mảng
và lấy dư với 10^9 + 7
*/

// Hướng dẫn: 
/*
(a + b) % c = ((a%c) + (b%c)) % c
(a - b) % c = ((a%c) - (b%c) + c) % c
(a x b) % c = ((a%c) * (b%c)) % c
*/
#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;

    ll sum = 0, tich = 1;
    int mod = 1e9 + 7;

    for (int i = 0; i < n; i++) {
    
        sum = ((sum % mod) + (a[i] % mod)) % mod;

       
        tich = ((tich % mod) * (a[i] % mod)) % mod;
    }

    cout << sum << endl;
    cout << tich << endl;
    return 0;
}

