/*
[Sắp xếp - Tìm kiếm]. Bài 50. Máy photo

Đề: Kì thi cuối kì môn Triết ở trường đại học xyz sắp diễn ra. Tèo và bạn bè có ý định sẽ photo phao thi để bán
kiếm tiền, hiện tại Tèo và bạn của mình đã có bản gốc của phao thi. Theo ước tính của Tèo thì có n bạn sẽ mua
phao thi của Tèo. Tèo không có ý định bán bản phao gốc của mình nên sẽ đi photo n bản nữa để bán, tới quán 
photo chỉ còn 2 máy photo có thể hoạt động. Trong đó máy photo 1 cần x giây để photo xong phao thi cho Tèo,
máy thứ 2 cần y giây. Vì muốn nhanh chóng đem phao đi bán nên Tèo muốn nhờ bạn tính hộ là anh ấy
cần ít nhất bao nhiêu giây để có thể photo ra n bản khác từ 1 bản gốc ban đầu. Chú ý các máy photo có thể 
photo từ bản gốc hoặc có thể photo từ bản sao đã được in từ bản gốc. 2 máy này có thể hoạt động một cách đồng thời
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(ll n, ll x, ll y, ll time) {
    time -= min(x, y);
    ll dem = time / x + time / y;
    return dem >= n - 1;
}
int main()
{
    ll n, x, y; cin >> n >> x >> y;
    ll left = 0, right = 1ll * min(x, y) * n;
    ll ans = -1;

    while(left <= right) {
        ll mid = (left + right) / 2;

        if (check(n, x, y, mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}