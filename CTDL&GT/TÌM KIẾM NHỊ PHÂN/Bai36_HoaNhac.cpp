/*
[Sắp xếp - Tìm kiếm]. Bài 36. Hòa nhạc

Đề: Có n vé xem hòa nhạc có sẵn, mỗi vé có một mức giá nhất định. Sau đó, m khách hàng lần lượt đế. Mỗi
khách hàng thông báo mức giá tối đa mà họ sẵn sàng trả cho một vé và sau đó họ sẽ nhận được một vé với
mức giá gần nhất có thể sao cho không vượt quá mức giá tối đa.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> ms;
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ms.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        auto it = ms.upper_bound(x);
        if (it != ms.begin()) {
            --it;
            cout << *it << ' ';
            ms.erase(it);
        } else {
            cout << "-1" << ' ';
        }
    }
    return 0;
}