/*
[DP. Bài 28. Select Array

Đề: Bạn biết rằng một mảng có n số nguyên chỉ gồm các số từ 1 đến m và độ lệch giữa 2 phần tử liền kề
trong mảng không được vượt quá 1 đơn vị. Bài toán đặt ra là cho bạn một mảnh trong đó một số
giá trị trong mảng chưa được xác định giá trị, nhiệm vụ của bạn là đếm số mảng phù hợp với mô tả,
đó là các số liền kề trong mảng không lệch nhau quá 1 đơn vị và các giá trị trong mảng chỉ được nằm
trong đoạn từ 1 tới m.

- Input: Dòng đầu nhập hai số nguyên n và m: kích thước mảng và giới hạn trên cho mỗi giá trị
         Dòng tiếp theo có n số nguyên x1, x2, ... , xn: nội dung của mảng. Giá trị 0 biểu thị một giá trị không xác định
- Output: In ra số lượng mảng phù hợp sau khi chia dư cho 1e9 + 7
*/
#include <bits/stdc++.h>
using namespace std;

long long F[1005][1005];

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (a[1] != 0) 
        F[1][a[1]] = 1;
    else {
        for (int j = 1; j <= m; j++) {
            F[1][j] = 1;
        }
    } 


    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= m; j++) {
                F[i][j] = F[i-1][j-1] + F[i-1][j] + F[i-1][j+1];
                F[i][j] %= mod;
            }
        }
        else {
            F[i][a[i]] = F[i - 1][a[i] - 1] + F[i - 1][a[i]] + F[i - 1][a[i] + 1];
            F[i][a[i]] %= mod;
        }
    }
    int res = 0;
    for (int j = 1; j <= m; j++) {
        res += F[n][j];
        res %= mod;
    }
    cout << res << endl;
    return 0;
}