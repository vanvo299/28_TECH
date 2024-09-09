/*
[Mảng 2 chiều]. Bài 27. Maximum Path Sum 3

Đề: Cho mảng 2 chiều A gồm N hàng và N cột, hàng được đánh số từ 1 đến N từ trên xuống dưới, cột được đánh
số từ 1 tới N từ trái sang phải, hãy tìm 1 đường đi từ một ô ở cột 1 tới 1 ô ở cột N sao cho các phần tử trên
đường đi đó là lớn nhất có thể. Biết rằng ở mỗi bước đi từ ô hiện tại (i, j) chỉ có thể đi sang phải (i, j + 1) hoặc đi
xuống ô dưới bên phải (i + 1, j + 1), ô bên trên bên phải (i - 1, j + 1). Hãy tìm 1 đường đi có tổng các số trên 
đường đi là lớn nhất
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int A[505][505];
ll F[505][505];
int n;


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }   

    // với các ô ở hàng đầu, cột đầu thì bị truy xuất tới ô không xác định
    // khởi tạo cho các ô này giá trị nhỏ
    for (int i = 1; i <= n; i++){
        F[0][i] = -1e8;
        F[n + 1][i] = -1e8;
    }
   for (int i = 1; i <= n; i++) {
        F[i][1] = A[i][1];
    } 

    for (int j = 2; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            F[i][j] += max({F[i + 1][j - 1], F[i][j - 1], F[i - 1][j - 1]}) + A[i][j];
        }
    }

    int max_sum = 0;
    for (int i = 1; i <= n; i++) {
        if (F[i][n] > max_sum) {
            max_sum = F[i][n];
        }
    }
    cout << max_sum << endl;
    return 0;
}