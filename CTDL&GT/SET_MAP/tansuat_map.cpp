/*
Cho mảng số nguyên A[] gồm N phần tử, hãy liệt kê các giá trị xuất hiện trong mảng theo thứ tự xuất hiện 
trong mảng kèm theo tần suất của nó, mỗi giá trị chỉ liệt kê một lần
*/
#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> mp; // key: giá trị của phần tử, value: tần suất xuất hiện
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    for (int i = 0; i < n; i++) {
        mp[a[i]]++; // tương tự như cách làm của mảng đánh dấu
    }
    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}