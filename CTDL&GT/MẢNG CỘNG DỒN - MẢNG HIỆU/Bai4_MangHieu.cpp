/*
[Mảng cộng dồn - Mảng hiệu]. Bài 4: Mảng hiệu

Đề: Cho mảng số nguyên A[] gồm N phần tử, mảng hiệu của mảng A là mảng D[] với D[0] = A[0] và D[i] = A[i] - A[i - 1].
Nhiệm vụ của bạn là xây dựng mảng hiệu của mảng A[]

*/

#include <iostream> 
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int D[n];
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            D[i] = a[i];
        }
        else D[i] = a[i] - a[i - 1];
    }

    for (int i = 0; i < n; i++) {
        cout << D[i] << " ";
    }
    return 0;
}