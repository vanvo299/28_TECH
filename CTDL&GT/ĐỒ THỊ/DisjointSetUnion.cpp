/*
CTDL: DISJOINT SET UNION

*Giới thiệu:
- Cấu trúc các tập hợp rời nhau (DSU) hay Union Find là một cấu trúc dữ liệu cực kì quan trọng và hiệu quả
- DSU giúp giải quyết bài toán: Cho một tập hợp các phần tử, ban đầu mỗi phần tử là một tập hợp riêng biệt. 
DSU cho phép gộp 2 tập hợp với nhau hoặc chỉ ra phần tử bất kì đang thuộc tập hợp nào.
- Trong tài liệu này, mình sử dụng mỗi phần tử riêng biệt là một đỉnh của đồ thị cho dễ tiếp cận,
tuy nhiên phạm vi của DSU không chỉ áp dụng trong đồ thị.

*Ban đầu đồ thị chứa N đỉnh, mỗi đỉnh là một tập hợp riêng biệt và có đại diện (cha) là chính
đỉnh đó. Mỗi lần bạn gộp 2 đinh lại với nhau, tương tự như có một cạnh nối giữa 2 đỉnh này.

*/
#include <bits/stdc++.h>
using namespace std;

int n; // Số đỉnh của đồ thị
int parent[10005], size[1005];

// Hàm khởi tạo này sẽ gán đại diện cho các đỉnh là chính nó
void ktao()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

// Tìm đỉnh đại diện cho tập hợp chứa đỉnh u
int Find(int u)
{
    if (u == parent[u]) return u;
    int tmp = Find(parent[u]);
    parent[u] = tmp;
    return tmp;
}

// Thao tác gộp 
// bool Union(int u, int v)
// {
//     u = Find(u); // tìm đại diện của đỉnh u
//     v = Find(v); // tìm đại diện của đỉnh v
//     if (u == v) return false; // không gộp được
//     if (u < v) parent[v] = u;
//        // Đỉnh nào lớn hơn thì đỉnh đó làm cha
//      else parent[u] = v;
//     return true; 
// }

// Tối ưu gộp thoe kích thước
bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v) return false;
    if (size[u] < size[v]) {
        swap(u, v); // u la thang co size lon hon
    }
    size[u] += size[v];
    parent[v] = u;
    return true;
}
int main()
{
    ktao();
    cout << Union(6, 7) << endl;
    cout << Union(5, 6) << endl;
    cout << Union(4, 5) << endl;
    cout << Union(2, 5) << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " " << parent[i] << endl;
    }

    return 0;
}
