/*
[Graph]. Bài 7. Danh sách cạnh sang ma trận kề (vô hướng)

Đề: Cho đồ thị vô hướng G = được biểu diễn dưới dạng danh sách cạnh. Hãy chuyển đổi đồ thị dưới dạng danh
sách cạnh này sang ma trận kề tương ứng

- Input: Dòng đầu tiên là 2 số n và m, tương ứng số lượng đỉnh và cạnh của đồ thị. Các đỉnh của đồ thị được đánh
số từ 1 tới n. M dòng tiếp theo mỗi dòng chứa đỉnh u, v tương ứng với một cạnh của đồ thị
- Output: In ra ma trận kề theo mẫu
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1][n + 1] = {0};

    while(m--) {
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    

    // in ma tran ke
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}