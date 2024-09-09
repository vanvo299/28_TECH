/*
[Chia và trị]. Bài 8. Trộn hai mảng

Đề: Cho hai mảng đã được sắp xếp A[], B[] gồm N, M phần tử theo thứ tự và số K. Nhiệm vụ
của bạn là tìm phần tử ở vị trí số K sau khi trộn hai mảng để nhận được một mảng đã sắp xếp
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (int &x : a) cin >> x;
    for (int &y : b) cin >> y;

    vector<int> v;

    int i = 0, j = 0;
    while(i < n && j < m) {
        if (a[i] <= b[j]) {
            v.push_back(a[i]);
            ++i;
        }
        else {
            v.push_back(b[j]);
            ++j;
        }
    }

    while(i < n) {
        v.push_back(a[i]);
        ++i;
    }
    while(j < m) {
        v.push_back(b[j]);
        ++j;
    }
    cout << v[k] << endl;
    return 0;
}