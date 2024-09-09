/*
[Hàm bổ sung]. Bài 9. Chữ số cuối cùng.

Đề: Tìm K chữ số cuối cùng của N^M, kết quả có thể không đủ K chữ số. Ví dụ 9^5 = 59049 và K = 3 thì bạn chỉ cần 
in ra 49. Gợi ý: Tính N^M chia dư cho 10^k;

*/

#include <iostream>
#include <cmath>
using namespace std;

using ll = long long;

int main()
{
    int n, m, k; cin >> n >> m >> k;
    int dem = 0;
    ll sum = 1;
    ll mod = pow(10, k);
    for (int i = 1; i <= m; i++) {
        sum *= n;
        sum %= mod;
    }
    cout << sum << endl;
    return 0;
}