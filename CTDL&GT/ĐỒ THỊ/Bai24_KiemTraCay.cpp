/*
[GRAPH]. Bài 24. Kiểm tra cây

ĐỀ: Một đồ thị N đỉnh là một cây, nếu như nó có đúng N - 1 cạnh và giữa 2 đỉnh bất kì, chỉ tồn 
tại duy nhất 1 đường đi giữa chúng. Cho một đồ thị vô hướng N đỉnh và N cạnh, hãy kiểm
tra đồ thị đã cho có phải là một cây hay không ?

- In ra 1 nếu đồ thị là cây, ngược lại in ra 0

* Tính chất của cây 
- Không có chu trình
- Giữa hai đỉnh chỉ có 1 đường đi duy nhất
- có N - 1 cạnh, N đỉnh (*)
- Là 1 đồ thị liên thông (*)

=> Cách kiểm tra đồ thị có phải là cây hay ko cần chứng minh
-   + có n - 1 cạnh
    + liên thông

-   + có n - 1 cạnh
    + ko có chu trình

*/
#include <bits/stdc++.h>
using namespace std;

int n, m; // Dinh, canh
int ok = 0;
vector<int> adj[1005];
bool visited[1005];
int height[1005];

// cach 1 : kiem tra cay co chu trinh hay khong
void DFS1(int u)
{
    
    visited[u] = true;
    // duyet ds ke cua dinh u
    for (int v : adj[u]) {
        if (!visited[v]) {
            height[u] = v;
            DFS1(v);
        }
        else if (v != height[u]) {
            ok = 1;
        }
    }
}

int checkTree()
{
    if (m != n - 1) return 0;
    DFS1(1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return 0;
        }
    }
    if (ok) return 1;
    else return 0;
}

// cach 2 : kiem tra do thi co lien thong hay khong 
int cnt = 0;

void DFS2(int u)
{
    cnt++;
    visited[u] = true;
    // duyet ds ke cua dinh u
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS2(v);
        }
    }
}

int kiemTraCay()
{
    if (m != n - 1) return 0;
    DFS2(1);
    if (cnt == n) return 1;
    return 0;
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

//    if (checkTree()) cout << 1 << endl;
//    else cout << 0 << endl;

   if (kiemTraCay()) cout << 1 << endl;
   else cout << 0 << endl;
    return 0;
}