// [MẢNG 1 CHIỀU CƠ BẢN]. BÀI 6: CẶP SỐ 1
/*
Cho mảng số nguyên A[] gồm N phần tử, hãy đễm xem trong mảng A[] tồn tại bao nhiêu
cặp số A[i], A[j] với i khác j sao cho tổng của 2 phần tử này bằng số k cho trước
*/
#include <iostream>
using namespace std;
int main()
{
    int n, k; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    cin >> k;

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == k) ++count;
        }
    }
    cout << count << "\n";
    return 0;
}
