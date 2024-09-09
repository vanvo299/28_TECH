/*
[GRAPH]. Bài 34. Họp mặt

ĐỀ: Có k người (1 <= K <= 100) đứng tại vị trí nào đó trong N địa điểm cho trước (1<=N<=1000)
được đánh số từ 1..N. Các điểm được nối với nhau bởi M đoạn đường 1 chiều(1 <= M <= 10000)
(Không có đoạn đường nào nối một điểm với chính nó). Mọi người muốn cùng tụ
họp tại một địa điểm nào đó. Tuy nhiên, với các đưognf đi cho trước, chỉ có một số địa
điểm nào đó có thể được chọn là điểm họp mặt. Cho trước K, N, M và vị trí ban đầu của K
người cùng với M đường đi một chiều, hãy xác định xem có bao nhiêu điểm có thể được chọn
làm điểm họp mặt

- Input: Dòng 1: Ghi 3 số: K, N và M. Dòng 2 đến K+1: dòng i + 1 chứa một số nguyên trong khoảng
(1..N) cho biết địa điểm mà người thứ i đang đứng. Dòng k + 2 đến M+K+1: Mỗi dòng ghi 
một cặp số A và B mô tả một đoạn đường đi một chiều  từ A đến B (cả hai trong khoảng 1..N và A!=B)

*/
#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt[10005];
vector<int> adj[1005];
bool visited[1005];

void DFS(int u)
{
    cnt[u]++;
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int main()
{
    cin >> k >> n >> m;
    int nguoi[k];
    for (int &x : nguoi) cin >> x;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int x : nguoi) {
        memset(visited, false, sizeof(visited));
        DFS(x);
    }
    cout << endl;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (k == cnt[i]) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}