/*
[GRAPH]. Bài 28. Đi tìm nhóm trưởng (Giải bằng DSU)

ĐỀ: Trong một lớp học luôn tồn tại những nhóm học sinh, các học sinh trong nhóm này sẽ
thân thiết với nhau hơn. Giả sử trong 1 nhóm, nếu bạn a chơi thân với bạn b và bạn b chơi
thân với bạn c, thì bạn a và bạn c sẽ chơi thân với nhau. Hiện nay Tèo là lớp trưởng lớp 
10A1, vì không thích việc chia bè kéo cánh trong lớp nên Tèo quyết định tìm các bạn nhóm 
trưởng của các nhóm để bàn việc hợp nhất các nhóm. Tèo biết rằng trong các nhóm nhỏ,
nhóm trưởng là người có nhiều quan hệ thân thiết với các thành viên khác trong nhóm
nhất và người có số thứ tự nhỏ nhất. Nếu một bạn nào đó không chơi với ai cả thì bạn 
đó là nhóm trưởng của chính mình. Bạn hãy giúp Tèo in ra thứ tự của các trưởng nhóm
theo thứ tự từ nhỏ đến lớn nhé.

-Input: Dòng đầu tiên là n và m, tương ứng với số lượng sinh viên trong lớp và số lượng tình bạn
giữa các bạn trong lớp. Các sinh viên được đánh số từ 1 tới n. M dòng tiếp theo mỗi dòng
gồm 2 số a, b thể hiện tình bạn thân thiết giữa bạn a và bạn b khác nhau 

*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[1005], bac[1005];

int Find(int u)
{
    if (u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    if (bac[x] > bac[y] || bac[x] == bac[y] && x < y) 
        parent[y] = x;
    else 
        parent[x] = y;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    vector<pair<int, int>> edges;
    while(m--) {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
        bac[x]++; bac[y]++;

    }
    for (auto it : edges) {
        Union(it.first, it.second);
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        if (i == parent[i]) {
            cout << i << ' ';
        }
    }
    return 0;
}