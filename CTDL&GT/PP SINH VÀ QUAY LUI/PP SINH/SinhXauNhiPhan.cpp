/*
- Thuật toán sinh xâu nhị phân
+ Ý tưởng: Đi tìm bit 0 đầu tiên tính từ bên phải, gặp bit 1 chuyển thành bit 0
VD: 0101111 => 0110000

*/
#include <iostream>
using namespace std;

using ll = long long;

int n, a[100], final = 0;

void ktao() 
{
    // khoi tao cau hinh dau tien
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }
}

void sinh() 
{
    int i = n; // bat dau tu bit cuoi cung
    while(i >= 1 && a[i] == 1) {
        a[i] = 0;
        --i;
    }
    if (i == 0) {
        final = 1; // day la cau hinh cuoi cung
    }
    else {
        a[i] = 1;
    }
}
int main()
{
    cin >> n;
    ktao();
    while(!final) {
        for (int i = 1; i <= n; i++) {
            cout << (char)(a[i] + 65);
        }
        cout << endl;
        sinh();
    }
    return 0;
}