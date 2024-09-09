/*
[GRAPH]. Bài 27. Nhóm bạn

ĐỀ: Trong một lơp học luôn tồn tại những nhóm học sinh, các bạn học sinh trong nhóm này sẽ thân thiết với 
nhau hơn. Giả sử trong 1 nhóm, nếu bạn a chơi thân với bạn b và bạn b chơi thân với bạn c, thì bạn a
và bạn c sẽ chơi thân với nhau. Hiện nay Tèo là lớp trưởng lớp 10A1, vì không thích việc chia bèo kéo
cánh trong lớp nên Tèo quyết định tìm ra nhóm có số bạn chơi thân với nhau nhất trong nhớm để đưa
các thành viên của các nhóm khác vào trong nhóm có số lượng thành viên cao nhất này. Bạn hãy giúp 
Tèo tìm ra số lượng thành viên lớn nhất của 1 nhóm chơi thân bất kỳ trong lớp nhé

- Input: Dòng đầu tiên là n và m, tương ứng với số lượng sinh viên trong lớp và số lượng tình bạn giữa các bạn
trong lớp. Các sinh viên được đánh số từ 1 tới n. M dòng tiếp theo mõi dòng gồm 2 số a, b thể hiện
tình bạn thân thiết giữa bạn a và bạn b, a và b khác nhau
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[1005];
vector<int> adj[1005];
int cnt = 0;

void DFS(int u)
{
    cnt++;
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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt = 0;
            memset(visited, false, sizeof(visited));
            DFS(i);
            res = max(res, cnt);
        }
    }
    cout << res << endl;
    return 0;
}