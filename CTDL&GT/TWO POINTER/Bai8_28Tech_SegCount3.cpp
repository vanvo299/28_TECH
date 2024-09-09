/*
[Two Pointer]. Bài 8. 28Tech_SegCount3

Đề: Cho mảng A[] gồm N phần tử và số nguyên K, nhiệm vụ của bạn là đếm xem có bao nhiêu mảng con các
phần tử liên tiếp trong mảng mà số lượng phần tử khác nhau trong mảng con này không vượt quá K.

*/

// Gợi ý: Dùng map
#include <iostream>
#include <map>
using namespace std;

using ll = long long;

int main()
{
    int n, s; cin >> n >> s;
    int a[n];
    for (int &x : a) cin >> x;

    int left = 0;
    ll res = 0;

    map <int, int> mp;
    for(int right = 0; right < n; right++) {
        mp[a[right]]++;
        while(mp.size() > s) {
            mp[a[left]]--;
            if (mp[a[left]] == 0) mp.erase(a[left]);
            ++left;
        }
        res += right - left + 1;
    }
    cout << res << endl;
    return 0;
}