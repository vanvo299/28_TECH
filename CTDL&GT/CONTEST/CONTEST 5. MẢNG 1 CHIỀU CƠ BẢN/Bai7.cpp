// [MẢNG 1 CHIỀU CƠ BẢN]. BÀI 7: CẶP SỐ 2
/*
Cho mảng số nguyên A[] gồm N phần tử, hãy tìm độ chênh lệch nhỏ nhất giữa 2 phần tử trong mảng
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;

    int min_val = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int tmp = abs(a[i] - a[j]);
            if (tmp < min_val) {
                min_val = tmp;
            }
        }
    }
    cout << min_val << "\n";
    return 0;
}
