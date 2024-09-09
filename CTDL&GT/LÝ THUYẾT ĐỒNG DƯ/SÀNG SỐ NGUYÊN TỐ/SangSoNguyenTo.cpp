/*
*** Thuật Toán Sàng Số Nguyên Tố Eratosthenes
- Sàng số nguyên tố là thuật toán giúp liệt kê nhanh các số nguyên tố trên đoạn từ 1 đến n, hoặc trong đoạn từ left tới right
- Nếu bạn muốn sàng có số nguyên tố không vượt quá n thì bạn phải tạo được mảng có kích thước n + 1 phần tử

*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// int prime[1000001];

// sang so nguyen to tu 1 den n
// void sangSoNT()
// {
//     // coi tat ca cac so tu 0->n la so nguyen to
//     //prime[i] = 1
//     // prime[i] = 0
//     for (int i = 0; i <= 1000001; i++) {
//         prime[i] = 1;
//     }
//     prime[0] = prime[1] = 0;
//     for (int i = 2; i <= 1000; i++) {
//         //neu i la so nguyen to
//         if(prime[i]) {
//             // Duyet tat ca cac boi so cua i va cho khong la so nguyen to
//             for (int j = i*i; j<= 1000001; j+=i) {
//                 prime[j] = 0; // j khong con la so nguyen to nua
//             }
//         }
//     }
// }

// sang so nguyen to tren doan, liet ke so nguyen to tren doan (l -> r) , lay ca l va r
// can tao mot mang co kich thuoc r - l + 1 phan tu
void sangSoNtTrenDoan(int l, int r) 
{
    int prime[r - l + 1];
    for (int i = 0; i <= r - l + 1; i++) {
        prime[i] = 1;
    }
    for (int i = 2; i <= sqrt(r); i++) {
        for (int j = max(i*i,(l + i - 1)/ i * i); j <= r; j+=i) {
            prime[j - l] = 0;
        }
    }
    for (int i = max(l, 2); i <= r; i++) {
        if (prime[i - l]) {
            cout << i << ' ';
        }
    }
}

int main() 
{
    int l, r; cin >> l >> r;
    sangSoNtTrenDoan(l, r);
    return 0;
}