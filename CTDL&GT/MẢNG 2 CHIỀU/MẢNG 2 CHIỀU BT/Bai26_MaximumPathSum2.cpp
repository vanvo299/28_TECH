/*
[Mảng 2 chiều]. Bài 26. Maximum path sum 2

Đề: Cho mảng 2 chiều A gồm N hàng và N cột, hãy tìm 1 đường đi từ dòng 1 tới dòng N sao cho các phần tử trên 
đường đi đó là lớn nhất. Biết rằng ở mỗi bước đi từ ô hiện tại chỉ có thể đi xuống ô dưới bên trái, ô dưới 
bên phải hoặc ô dưới của ô hiện tại. Hãy tìm 1 đường đi có tổng các số trên đường đi là lớn nhất
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int A[505][505];
ll F[505][505]; // Mảng kết quả
int n;

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    // Hàng 1 của mảng kết quả với mảng A là như nhau
    // kết quả chỉ cần tìm max trên hàng cuối của mảng kêts quả
    for (int j = 1; j <= n; j++) {
        F[1][j] = A[1][j];
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            F[i][j] += max({F[i - 1][j + 1], F[i - 1][j], F[i - 1][j - 1]}) + A[i][j];
        }
    }
    int max_value = 0;
    for (int j = 1; j <= n; j++) {
        if (F[n][j] > max_value) {
            max_value = F[n][j];
        }
    }
    cout << max_value << endl;
    return 0;
}