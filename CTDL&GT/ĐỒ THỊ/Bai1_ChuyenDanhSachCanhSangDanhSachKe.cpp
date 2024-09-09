/*
[Graph]. Bài 1. Chuyển danh sách cạnh sang danh sách kề (Vô hướng)

Đề: Cho đồ thị vô hướng G = được biểu diễn dưới dạng danh sách cạnh. Hãy chuyển đổi đồ thị dưới dạng danh
sách cạnh này sang danh sách kề tương ứng

- Input: Dòng đầu tiên là 2 số n và m, tương ứng số lượng đỉnh và cạnh của đồ thị. Các đỉnh của đồ thị được đánh
số từ 1 tới n. M dòng tiếp theo mỗi dòng chứa đỉnh u, v tương ứng với một cạnh của đồ thị
- Ouput: In ra n dòng, trong đó dòng thứ i in ra danh sách kề của đỉnh i. Các đỉnh trong danh sách kề được liệt  kê từ
nhỏ tới lớn

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
int main()
{
    int n, m; // đỉnh, cạnh
    cin >> n >> m;

    while(m--) {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v); // bổ sung v vào ds kề của u
        ke[v].push_back(u); // bổ sung u vào ds kề của v
    }

    // sap xep cac danh sach ke
    for (int i = 1; i <= n; i++) {
        sort(ke[i].begin(), ke[i].end());
    }

    // in danh sach ke
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int v : ke[i]) {
            cout << v << ' ';
        }
        cout << endl;
    }
    return 0;
}