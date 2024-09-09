/*
[Tham lam]. Largest Permutaion

Đề: You are given an unordered array of unique integers incrementing from 1. You can swap any two elements a
limited number of times. Determine the largest lexicographical value array that can be created by executing 
no more than the limited number of swaps.

Dịch: Bạn được cho một mảng không có thứ tự của các số nguyên duy nhất tăng dần từ 1. Bạn có thể hoán đổi bất kỳ 
hai phần tử nào một số lần nhất định. Xác định giá trị từ điển lớn nhất của mảng có thể được tạo ra bằng cách thực 
hiện không quá số lần hoán đổi giới hạn. 

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    int a[n + 1];
    vector<int> v;
    int pos[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // a[i] : n - i + 1
        pos[a[i]] = i; 
        if (a[i] != n - i + 1) {
            v.push_back(a[i]);
        }
    }

    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++) {
        if (k == 0) break;
        // khi can swap
        int x = v[i], pos1 = pos[x];
        int y = a[n - x + 1], pos2 = pos[y];
        if (pos1 != pos2) {
            swap(a[pos1], a[pos2]);
            pos[x] = pos2;
            pos[y] = pos1;
            k--;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}