/*
- Sinh nhị phân bằng phương pháp quay lui
*/
#include <bits/stdc++.h>
using namespace std;

int X[100], n, cnt = 0;

void in() 
{
    for (int i = 1; i <= n; i++) {
        cout << X[i];
    }
}
void Try(int i) 
{
    ++cnt; // đếm xem có bao nhiêu lần gọi đệ quy
    // Gán các giá trị có thể cho bit thứ i
    for (int j = 0; j <= 1; j++) {
        X[i] = j;
        if (i == n) {
            in();
            cout << endl;
        }
        else Try(i + 1);
    }
    cout << cnt << endl;
}
int main()
{
    cout << "Nhap n: ";
     cin >> n;
     Try(1);
    return 0;
}