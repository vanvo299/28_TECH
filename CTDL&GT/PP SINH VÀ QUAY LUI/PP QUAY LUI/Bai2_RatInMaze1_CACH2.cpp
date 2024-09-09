/*
[Quay lui - nhánh cận]. Bài 2. Rat in Maze 1

Đề: Cho một mê cung được mô tả dưới dạng một ma trận nhị phân có N hàng và N cột. Một con chuột bắt đầu từ
ô (1, 1) và muốn di chuyển tới ô (N, N). Con chuột chỉ được di chuyển xuống dưới hoặc sang phải và chỉ được di 
chuyển tới ô nào đó nếu ô đó có giá trị là 1. Bạn hãy in ra các cách đi hợp lệ của con chuột,trong đó nếu con 
chuột đi sang phải thì nước đi được mô tả là chữ R, và nếu con chuột đi xuống dưới thì nước đi được mô tả là 
chữ D. Nếu con chuột không thể đi xuống ô (N, N) thì in ra -1. Chú ý trên mỗi đường đi con chuột chỉ có thể đi
qua 1 ô nào đó đúng 1 lần.

*/


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, a[100][100], check = 0;
string S = "";
string path = "DR";

int dx[] = { 0, 1 };
int dy[] = { 1, 0 };


void Try(int i, int j)
{
	if (i == n && j == n) {
        check = 1;
		cout << S << endl;
	}

	for (int k = 0; k < 2; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 1) {
			a[i1][j1] = 0;
			S += path[k];
			Try(i1, j1);
			a[i1][j1] = 1;
			S.pop_back();
		}
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
	Try(1, 1);
    if (check == 0) cout << "-1" << endl;
	cout << endl;
	return 0;
}