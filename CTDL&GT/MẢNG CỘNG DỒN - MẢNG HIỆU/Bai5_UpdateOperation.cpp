/*
[Mảng cộng dồn - Mảng hiệu]. Bài 5: Update Operation

Đề: Cho mảng số nguyên A[] gồm N phần tử, có Q thao tác, mỗi thao tác yêu cầu các bạn tăng tất cả các phần tử 
từ chỉ số L đến chỉ số R lên K đơn vị. Hãy in ra mảng sau khi thực hiện các thao tác trên.

*/

#include <iostream>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    int A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int D[n + 2];
    // Xay dung mang hieu
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            D[0] = A[0];
        } else {
            D[i] = A[i] - A[i - 1];
        }
    }

    // Thuc hien thao tac de bai yeu cau
    while(q--) {
        int L, R, K;
        cin >> L >> R >> K;
        D[L] += K;
        D[R + 1] -= K;
    }

    int F[n];
    for (int i = 0; i < n; i++) {
        if (i == 0) F[i] = D[i]; 
        else F[i] = F[i - 1] + D[i];
    }

    for (int i = 0; i < n; i++) {
        cout << F[i] << " ";
    }
    return 0;
}