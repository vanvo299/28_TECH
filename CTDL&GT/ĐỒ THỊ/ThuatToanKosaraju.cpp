/*
[GRAPH]. Thuật toán Kosaraju
- Thuật toán Kosaraju có thể dùng liệt kê các thành phần liên thông mạnh
của đồ thị và vì thê cũng có thể sử dụng để kiểm tra đồ thị liên thông mạnh. 
Độ phức tạp của Kosaraju tương tự như DFS: O(V + E)

- Thuật toán Kosaraju:
+ Bước 1: Tạo một ngăn xếp rỗng để lưu thứ tự duyệt xong các đỉnh của đồ thị, đỉnh 
nào được duyệt xong trước sẽ được đẩy vào ngăn xếp (Tương tự như topo)
+ Bước 2: Lật ngược hướng của các cạnh trên đồ thị ban đầu để thu đươc đồ thị chuyển vị
(transpose graph)
+ Bước 3: Lần lượt lấy các đỉnh trong ngăn xếp và nếu đỉnh này chưa được duyệt trong các thành
phần liên thông mạnh trước đó thì lấy đỉnh này làm đỉnh nguồn và gọi thuật toán DFS(trên đồ thị
transpose ở bước 2) để in ra các đỉnh trong thành phần liên thông
*/
#include <bits/stdc++.h>
using namespace std;

int n, m; // Đỉnh, cạnh
vector<int> adj[1005];
vector<int> t_adj[1005];
bool visited[1005];
stack<int> st;

void nhap()
{
    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        t_adj[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
}

// duyệt các đỉnh trong đồ thị ban đầu
void DFS1(int u) 
{
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS1(v);
        }
    }
    st.push(u); // duyet xong u
}

// duyệt các đỉnh trong đồ thị sau khi lật ngược
void DFS2(int u)
{
    cout << u << ' ';
    visited[u] = true;
    for (int v : t_adj[u]) {
        if (!visited[v]) {
            DFS2(v);
        }
    }
}

void Kosaraju()
{
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS1(i);
        }
    }
    memset(visited, false, sizeof(visited));
    int scc = 0; // số thành phần liên thông mạnh  
    while(!st.empty()) {
        int u = st.top(); st.pop();
        if (!visited[u]) {
            ++scc;
            cout << "SCC " << scc << " : ";
            DFS2(u); cout << endl;
        }
    }
}
int main()
{
    nhap();
    Kosaraju();
    return 0;
}