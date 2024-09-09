/*
[Quay lui - Nhánh cận]. Bài 3. Rat in Maze 2

Đề: Cho một mê cung được mô tả dưới dạng một ma trận nhị phân có N hàng và N cột. Một con chuột bắt đầu từ
ô (1, 1) và muốn di chuyển tới ô (N, N). Con chuột chỉ được di chuyển sang trái, sang phải, lên trên và xuống 
dưới và chỉ được di chuyển tới ô nào đó nếu ô đó có giá trị là 1. Bạn hãy in ra các cách đi hợp lệ của con chuột,
trong đó nếu con chuột đi sang phải thì nước đi được mô tả là chữ R, và nếu con chuột đi xuống dưới thì nước 
đi được mô tả là chữ D, nếu đi sang trái thì nước đi được mô tả là chữ L, nếu đi lên trên thì nước đi được mô tả
là chữ U. Nếu con chuột không thể đi xuống ô (N, N) thì in ra -1. Chú ý trên mỗi đường đi con chuột chỉ có thể
đi qua 1 ô nào đó đúng 1 lần.
*/

#include <iostream>
#include <string>
using namespace std;

int n, a[100][100], check = 0;
string S = "";

// thử đi vào ô i, j
void Try(int i, int j)
{
    if (i == n && j == n) {
        check = 1;
        cout << S << endl;
    }

    if (i + 1 <= n && a[i + 1][j] == 1) {
        S += "D";
        a[i + 1][j] = 0;
        Try(i + 1, j);
        S.pop_back();
        a[i + 1][j] = 1;
    }

    if (j + 1 <= n && a[i][j + 1] == 1) {
        S += "R";
        a[i][j + 1] = 0;
        Try(i, j + 1);
        S.pop_back();
        a[i][j + 1] = 1;
    }
    if (i - 1 > 0 && a[i - 1][j] == 1) {
        S += "U";
        a[i - 1][j] = 0;
        Try(i - 1, j);
        S.pop_back();
        a[i - 1][j] = 1;
    }
    if (j - 1 > 0 && a[i][j - 1] == 1) {
        S += "L";
        a[i][j - 1] = 0;
        Try(i, j - 1);
        S.pop_back();
        a[i][j - 1] = 1;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    if (a[1][1]) {
        a[1][1] = 0;
        Try(1, 1);
        if (check == 0) cout << "-1" << endl;
        cout << endl;
    } else cout << "-1" << endl;
    return 0;
}