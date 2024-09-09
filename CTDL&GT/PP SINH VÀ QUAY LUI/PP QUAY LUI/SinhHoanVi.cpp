/*
- Thuật toán sinh hoán vị bằng phương pháp quay lui
*/

#include <bits/stdc++.h>
using namespace std;

int n, X[100], daXet[100], cnt = 0;

void in()
{
    for (int i = 1; i <= n; i++) {
        cout << X[i];
    }
}

void Try(int i)
{
    cnt++;
    for (int j = 1; j <= n; j++) {
        // kiểm tra xem có thể gán j cho X[i] không ?
        if(daXet[j] == 0) {
            X[i] = j; 
            daXet[j] = 1;
            if (i == n) {
                in();
                cout << endl;
            } 
            else Try(i + 1);
            // bỏ ghi nhận
            daXet[j] = 0;
        }
    }
}
int main()
{
    cin >> n;
    Try(1);
    return 0;
}