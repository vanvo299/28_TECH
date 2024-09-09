/*
Thuật toán Prim - Tìm cây khung nhỏ nhất

- Tư tưởng của thuật toán Prim đó là duy trì 2 tập đỉnh V: tập đỉnh ban đầu và MST
là tập đỉnh cây khung. Thuật toán Prim sẽ bắt đầu với một đỉnh bất kỳ của đồ thị. 
Ban đầu MST = {s}, s là đỉnh bắt đầu của thuật toán, V = V\{s}
- Mỗi bước chọn ra 1 cạnh có trọng số nhỏ nhất mà 1 đỉnh của cạnh này thuộc tập 
V và đỉnh còn lại thuộc tập MST sau đó đưa đỉnh này vào cây khung. Cập nhật V
và MST. Thuật toán kết thúc khi cây khung đủ n - 1 cạnh hoặc tập V rỗng.


- Để có thể nhanh chóng tìm ra cạnh có độ dài ngắn nhất để nạp vào cây khung, ta
sử dụng hàng đợi ưu tiên. Hàng đợi ưu tiên này lưu pair, trong đó first lưu trọng
số và second lưu đỉnh.
- Để kiểm tra đỉnh thuộc tập V hay MST ta dùng mảng đánh dấu taken[], trong đó
taken[u] = true nếu đỉnh u thuộc tập MST, ngược lại thuộc tập V

*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> adj[100001];
bool taken[1000001];

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void Prim(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

}
int main()
{

    return 0;
}