/*
[GRAPH]. Bài 28. Đi tìm nhóm trưởng

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

int n, m; // số lượng sinh viên và số lượng tình bạn
bool visited[1005];
vector<int> adj[1005];
int bac[1005];
int nhomTruong = 0;

void DFS(int u)
{
    if (bac[u] > bac[nhomTruong] || bac[u] == bac[nhomTruong] && u < nhomTruong) {
        nhomTruong = u;
    }
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}
int main()
{
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        bac[a]++; bac[b]++;
    }
    int res = INT_MIN;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if(!visited[i]) {  
            nhomTruong = i;
            DFS(i);
            v.push_back(nhomTruong);
        }
    }
    sort(v.begin(), v.end());
    for (int i : v) {
        cout << i << ' ';
    }
    return 0;
}