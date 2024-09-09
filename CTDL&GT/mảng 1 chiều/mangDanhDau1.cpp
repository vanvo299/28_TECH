// Bài 27: Mảng đánh dấu 2
/*
Cho mảng số nguyên A[] gồm n phần tử, hãy liệt kê các giá trị xuất hiện trong mảng theo thứ tự từ nhỏ đến
lớn kèm theo tần suất của nó.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int cnt[1000001];
int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    for (int i = 0; i <= 100000; i++) {
        if(cnt[i]) {
            cout << i << " " << cnt[i] << endl;
        }
    }
    
    return 0;
}