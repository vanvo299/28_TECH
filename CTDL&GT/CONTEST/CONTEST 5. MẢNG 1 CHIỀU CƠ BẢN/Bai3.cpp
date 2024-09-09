// [MẢNG 1 CHIỀU CƠ BẢN]. BÀI 2: SỐ NHỎ NHẤT
/*
Cho mảng số nguyên A[] gồm n phần tử, hãy đếm xem trong mảng của bạn có bao nhieu
số có cùng giá trị nhỏ nhất. Ví dụ mảng A = {1, 2, 1, 3, 5} thì số nhỏ nhất trong mảng là 1
xuất hiện 2 lần
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;

    int min_val = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < min_val) {
            min_val = a[i];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == min_val) {
            ++count;
        }
    }
    cout << count << endl;
    return 0;
}
