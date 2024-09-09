/*
[Sắp xếp - Tìm kiếm]. Bài 37. Cửa hàng bận rộn

Đề: Bạn được cho biết thời gian đến và đi của n khách hàng trong một nhà hàng. Số lượng khách hàng có mặt tại
cửa hàng ở 1 thời điểm nhiều nhất là bao nhiêu.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> v;
    int n; cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }

    sort(v.begin(), v.end());
    int dem = 0, res = 0;
    for (int i = 0; i < v.size(); i++) {
        res += v[i].second;
        dem += max(dem, res);
    }
    cout << dem << endl;
    return 0;
}