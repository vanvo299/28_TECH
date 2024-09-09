// Bài 33: Xoay trái
/*
Cho mảng A[] gồm N phần tử, hãy dịch các phần tử trong mảng sang trái k vị trí, khi dịch trái thì phần tử
cuối cùng của dãy sẽ qua vòng lại thành phần tử đầu tiên

** Input format: - Dòng 1 gồm N và K
                 - Dòng 2 gồm N số của mảng A[]
** Output format: - In ra mảng sau khi xoay trái

Example: 
8 6
16 66 96 73 11 13 99 82

99 82 16 66 96 73 11 13
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    
    // k = k % n;


    int tmp[k];
    // sao chép k phần tử vị trí đầu của mảng sang mảng phụ
    for (int i = 0; i < k; i++) {
        tmp[i] = a[i];
    }

    // dịch các phần tử còn lại sang trái
    for (int i = k; i < n; i++) {
        a[i - k] = a[i];
    }

    // sao chép các phần tử ở mảng phụ sang mảng chính
    for (int i = 0; i < k; i++) {
        a[n - k + i] = tmp[i];
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}