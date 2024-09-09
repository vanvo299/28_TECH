/*
- Sinh tổ hợp chập K của N phần tử
- Cho các số tự nhiên từ 1 đến N, nhiệm vụ của bạn là liệt kê các tập con có K phẩn tử 
của tập N phần tử này theo thứ tự từ điển tăng dần
- Ý tưởng: Tìm số từ phải sang mà số tại vị trí i đó chưa đạt giá trị cực đại n - k + i, nếu tìm được thì tăng số tại i lên 1 đơn vị
và các số sau i mỗi số tăng lên 1 đơn vị
*/
#include <bits/stdc++.h>
using namespace std;

int n, k, a[100], final = 0;

void ktao()
{
    // khoi tao cau hinh dau tien
    for (int i = 1; i <= k; i++) {
        a[i] = i;
    }
}

void sinh()
{
    int i = k;
    while(i >= 1 && a[i] == n - k + i) {
        --i;
    }
    if (i == 0) {
        final = 1;
    }
    else {
        ++a[i];
        for (int j = i + 1; j <= k; j++) {
            a[j] = a[j - 1] + 1;
        }
    }
}

vector<vector<int>> res;
int main()
{
    cin >> n >> k;
    ktao();
    while(!final) {
        vector<int> tmp;
        for (int i = 1; i <= k; i++) {
            tmp.push_back(a[i]);
        }
        res.push_back(tmp);
        sinh();
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        for (int &x : res[i]) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}