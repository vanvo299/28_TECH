// [MẢNG 1 CHIỀU CƠ BẢN]. BÀI 10: CÂN BẰNG NGUYÊN TỐ
/*
Cho mảng số nguyên A[] gồm N phần tử, liệt kê các số thuộc dãy fibonacci có trong mảng
*/
#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

ll F[100];
void fibonacci()
{
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i < 93; i++) { // 93 la chi so fibo cuoi cung luu trong long long
        F[i] = F[i - 1] + F[i - 2];
    }
}

int find(ll x)
{
    for (int i =0; i < 93; i++) {
        if (F[i] == x) return 1;
    }
    return 0;
}
int main()
{
    fibonacci();
    int n, x; cin >> n;
    ll a[n];
    for (ll &x : a) cin >> x;
    
    int check = 0;
    for (ll x : a) {
        if (find(x)) {
            cout << x << " ";
            check = 1;
        }
    }
    if (!check) cout << "NONE!!!\n";
    
    return 0;
}
