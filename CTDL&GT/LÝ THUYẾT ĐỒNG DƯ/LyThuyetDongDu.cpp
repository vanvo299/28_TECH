/*
  
** Công thức về lý thuyết đồng dư:
- (A + B) % C = ((A % C) + (B % C)) % C
- (A - B) % C = ((A % C) - (B % C)) % C
- (A + B) % C = ((A % C) + (B % C)) % C
- (A / B) % C = ((A % C) * (B^-1 % C)) % C
=> Có thể áp dụng khi có nhiều số


*/
#include <iostream>
using namespace std;

using ll = long long;

int main()
{
// // tinh giai thua (1.2.3.4.5.....N) % (1e9 + 7);
//     int n; cin >> n;
//     ll factorial = 1;
//     for (int i = 1; i <= n; i++) {
//         factorial = (factorial % 1000000007) * (i % 1000000007) % 1000000007;
//     }
//     cout << factorial % 1000000007;

// tinh a^b % c
    int a, b, c; cin >> a >> b >> c;
    ll kq = 1;
    for (int i = 1; i <= b; i++) {
        kq *= a;
        kq %= c;
    }
    cout << kq << endl;
    return 0;
}