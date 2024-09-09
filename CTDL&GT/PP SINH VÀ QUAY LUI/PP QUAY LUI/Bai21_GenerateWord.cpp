/*
[Quay lui - Nhánh cận]. Bài 21. Generate Word

Đề: Cho một bảng HCN cỡ N hàng, M cột, mỗi ô trên HCN chứa 1 chữ cái in hoa hoặc chữ số. Một từ có thể được 
xây dựng từ các chữ cái của các ô liền kề theo thứ tự, trong đó các ô liền kề nằm cạnh nhau theo chiều ngang
hoặc chiều dọc. Không được sử dụng cùng 1 ô chũ cái nhiều lần. Bạn hãy xác định xem có thể  tạo thành từ 
S cho trước hay không ?
*/

// Fact: Ta sinh ra tất cả mọi từ có thể tạo từ bảng HCN rồi so sánh các từ đã tạo với từ đã cho ban đầu 
#include <bits/stdc++.h>
using namespace std;

int n, m, ok = 0;
char a[100][100];
string s, tmp = "";
bool visited[100][100];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

void Try(int i, int j)
{
    cout << tmp << endl;
    if (ok) return;
    
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && visited[i1][j1] == 0) {
            tmp += a[i1][j1];
            visited[i1][j1] = 1;
            if (tmp == s) {
                ok = 1;
                return;
            }
            else if (s.find(tmp) != string::npos) {
                Try(i1, j1);
            }
            // backtrack
            tmp.pop_back();
            visited[i1][j1] = 0;
        }
    }
    
}
int main()
{
    nhap();
    cin >> s;

    // Kiểm tra nên bắt đầu từ ô nào trong ô chữ hình chữ nhật
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == s[0]) {
                memset(visited, 0, sizeof(visited)); // Reset tất cả giá trị trong mảng visited về giá trị 0
                tmp = "";
                tmp += a[i][j];
                visited[i][j] = 1;
                Try(i, j);
                if (ok) {
                    cout << "YES" << endl;
                    return 0;
                } 
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}