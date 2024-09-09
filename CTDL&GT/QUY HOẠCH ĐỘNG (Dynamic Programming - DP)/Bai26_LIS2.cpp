/*
[DP]. Bài 26. LIS 2

Đề: Bạn được cung cấp một mảng chứa nn số nguyên. Nhiệm vụ của bạn là xác định dãy con dài nhất tăng dần
trong mảng, tức là dãy con dài nhất mà mọi phần tử đều lớn hơn phần tử trước đó. Một dãy con là một dãy có
thể được dẫn xuất từ mảng bằng cách xóa một số phần tử mà không làm thay đổi thứ tự của các phần tử còn lại

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if (it == v.end()) {
            // Nếu it trỏ đến cuối vector v, tức là a[i] lớn hơn tất cả các phần tử hiện tại trong v
            v.push_back(a[i]);
        } 
        else {
            *it = a[i];
        }
    }
    cout << n - v.size() << endl;
    
    // in ra dãy tăng dần dài nhất
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ' ;
    }
    return 0;
}