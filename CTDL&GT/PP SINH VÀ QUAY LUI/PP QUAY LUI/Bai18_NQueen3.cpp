/*
[Quay lui - Nhánh cận]. Bài 18. N Queen 3

Đề: Vẫn là bài toán N quân hậu, nhiệm vụ của bản là hãy in ra cách xếp quân hậu trên bàn cờ cỡ N * N. Trong
đó với mỗi ô trên bàn cờ có quân hậy chiếm chỗ sẽ đại diện là chữ Q, ngược lại ô trống sẽ là dấu '.'
*/
#include <bits/stdc++.h>
using namespace std;

int n, Cot[100], cheo1[100], cheo2[100], X[100];

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (Cot[j] == 0 && cheo1[i + j - 1] == 0 && cheo2[i - j + n] == 0) {
            X[i] = j;
            Cot[j] = 1;
            cheo1[i + j - 1] = 1;
            cheo2[i - j + n] = 1;
            if (i == n) {
                // in cau hinh
                for (int row = 1; row <= n; row++) {
                    for (int column = 1; column <= n; column++) {
                        if (X[row] == column) {
                            cout << "Q";
                        } else {
                            cout << ".";
                        }
                    }
                    cout << endl;
                }
                cout << endl;
            } else {
                Try(i + 1);
            }
            Cot[j] = 0;
            cheo1[i + j - 1] = 0;
            cheo2[i - j + n] = 0;
        } 
    }
}
int main()
{
    cin >> n;
    Try(1);
    return 0;
}