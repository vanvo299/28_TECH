/*
[Two Pointer]. Bài 9. 28Tech_SegCount4

Đề: Cho mảng A[] gồm N số nguyên và số nguyên K, nhiệm vụ của bạn là đếm xem có bao nhiêu mảng con các
phần tử liên tiếp trong mảng mà độ chênh lệch giữa phần tử lớn nhất và phần tử nhỏ nhất trong mảng con đó
không vượt quá K.
*/

#include <iostream>
#include <set>
using namespace std;

using ll = long long;

int main()
{
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;

    int left = 0;
    ll res = 0;

    multiset<int> st;
    for (int right = 0; right < n; right++) {
        st.insert(a[right]);
        while(st.size() >= 1 &&  (*st.rbegin() - *st.begin() > k)) {
            auto it = st.find(a[left]);
            st.erase(it);
            ++left;
        }
        res += right - left + 1;
    }
    cout << res << endl;
    return 0;
}