/*
[GRAPH]. Bài 45. Truy vấn đường đi

ĐỀ: Cho đơn đồ thị vô hướng liên thông G = (V, E) gồm N đỉnh và M cạnh, các đỉnh được đánh số từ 1 tới N và các 
cạnh được đánh số từ 1 tới M. Có Q truy vấn, mỗi truy vấn yêu cầu bạn tìm đường đi ngắn nhất giữa đỉnh X tới đỉnh Y

Input:
- Dòng đầu tiên là 2 số nguyên N và M
- M dòng tiếp theo, mỗi dòng gồm 3 số nguyên u,v, c cho biết có cạnh nối giữa 2 đỉnh u và v có độ dài bằng c (trọng số)
- Tiếp theo là số lượng truy vấn Q
- Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên X, Y (Đỉnh X và đỉnh Y).

Output: với mỗi truy vấn, in ra đáp án là độ dài đường đi ngắn nhất tìm được.
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, a[105][105];

void Nhap()
{
    cin >> n >> m;
    // Khởi tạo
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) a[i][j] = 0;
            else a[i][j] = 1e9;
        }
    }
    // Nhap
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        a[x][y] = w;
        a[y][x] = w;
    }
}

void FLoyd()
{
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
}
int main()
{
    Nhap();
    FLoyd();
    vector<int> res;
    int q; cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        res.push_back(a[x][y]);
    }

    for (auto it : res) {
        cout << it <<  endl;
    }
    return 0;
}