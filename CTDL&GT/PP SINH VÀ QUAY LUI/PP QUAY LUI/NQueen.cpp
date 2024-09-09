/*
[Quay lui - Nhánh cận]. Bài 6. Bài toán N Queen

*/
#include <bits/stdc++.h>
using namespace std;

int n, X[100], cnt = 0;
int cot[100], cheo1[100], cheo2[100]; // 3 mang danh dau de danh dau 

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
                for (int i = 1; i <= n; i++) {
                    cout << "Con hau hang " << i << " nam o cot " << X[i] << endl;
                }
                cout << endl;
            } else Try(i + 1);

            cot[j] = 0;
            cheo1[i - j + n] = 0;
            cheo2[i + j - 1] = 0;
        }
    }
}
int main()
{
    cin >> n;
    Try(1);
    cout << "Co " << cnt << " cach xep quan hau" << endl;
    return 0;
}