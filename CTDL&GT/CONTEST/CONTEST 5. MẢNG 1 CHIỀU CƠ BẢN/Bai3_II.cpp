// [MẢNG 1 CHIỀU]. BÀI 3. Số lớn hơn các số đứng trước
/*
Cho một dãy số nguyên dương có n phần tử. Hãy liệt kê các phần tử trong dãy 
tất cả các số đứng trước nó (Phần tử đầu tiên được coi là một phần tử thỏa mãn).
*/
#include <iostream>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    int max_val = -1e9;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (a[i] > max_val) {
            cout << a[i] << " ";
            max_val = a[i];
        }
    }
    return 0;
}