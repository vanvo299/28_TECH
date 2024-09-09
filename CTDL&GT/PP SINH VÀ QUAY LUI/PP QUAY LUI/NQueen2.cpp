/*
[Quay lui - Nhánh cận]. Bài 7. Bài toán N Queen 2

Đề: Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][j] nhất định(0 <= A[i][j] <= 100), tương ứng với điểm số đạt được
nếu như bạn đặt một quân cờ vào đó. Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, sao cho không có 2 
quân nào ăn nhau, và số điểm đạt được là lớn nhất.

*/
#include <bits/stdc++.h>
using namespace std;

int n, X[100], cnt = 0;
int cot[100], cheo1[100], cheo2[100]; // 3 mang danh dau de danh dau 
int A[100][100], tmp = 0;

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        // lua chon cot j de dat con hau o hang thu i
        if (cot[j] == 0 && cheo1[i - j + n] == 0 && cheo2[i + j - 1] == 0) {
            // Kiem tra xem vi tri de dat con hau o vi tri j duoc khong
            X[i] = j;
            cot[j] = 1;
            cheo1[i - j + n] = 1;
            cheo2[i + j - 1] = 1;
            if (i == n)  {
                ++cnt;
                int Tong = 0;
                for (int hang = 1; hang <= n; hang++) {
                    Tong += A[hang][X[hang]];
                }
                tmp = max(tmp, Tong);
            } else Try(i + 1);

            cot[j] = 0;
            cheo1[i - j + n] = 0;
            cheo2[i + j - 1] = 0;
        }
    }
}
int main()
{
    n = 8;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }
    Try(1);
    cout << tmp << endl;
    return 0;
}