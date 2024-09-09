// [MẢNG 1 CHIỀU CƠ BẢN]. BÀI 5: IN PHẦN TỬ
/*
Cho mảng số nguyên A[] gồm N phần tử. Nhiệm vụ của bạn là in ra các phần tử là số chẵn
ở chỉ số chẵn, nếu mảng không tồn tại phần tử như vậy thì in ra "NONE"
*/
#include <iostream> 
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    int check = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && a[i] % 2 == 0) {
            check = 1;
            cout << a[i] << ' ';
        } 
    }
    if (check == 0) cout << "NONE";
    return 0;
}
