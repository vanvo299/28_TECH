/*
Bài 5. Di chuyển trong mê cung
Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:
Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.

Hãy đưa ra một hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.             

*/
#include <bits/stdc++.h>
using namespace std;

int n, a[10][10];
string s = "";

void Try(int i, int j)
{
    if (i == n && j == n) {
        cout << s << endl;
    }

    // gán nước đi tiếp theo khi con chuột đang ở ô (i, j)
    if (i + 1 <= n && a[i + 1][j] == 1) {
        s += "D";
        a[i + 1][j] = 0; // đánh dấu ô này đã đi qua rồi
        Try(i + 1, j);
        s.pop_back(); // xóa nước đi cuối cùng
        a[i + 1][j] = 1; 
    }
    
    if (j + 1 <= n && a[i][j + 1] == 1) {
        s += "R";
        a[i][j + 1] = 0;
        Try(i, j + 1);
        s.pop_back();
        a[i][j + 1] = 1;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        Try(1, 1);
        cout << endl;
    }
    return 0;
}