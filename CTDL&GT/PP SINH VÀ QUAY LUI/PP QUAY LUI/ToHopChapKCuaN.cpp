/*
- Thuật toán sinh tổ hợp chập K của N phần tử bằng phương pháp quay lui
*/

#include <bits/stdc++.h>
using namespace std;

int n, X[100], cnt = 0, k;

void in()
{
    for(int i = 1; i <= k; i++) {
        cout << X[i];
    }
}

void Try(int i)
{
       for (int j = X[i - 1] + 1; j <= n - k + i; j++){
        // Giá trị nhỏ nhất tại X[i] là X[i - 1] + 1 
        // Giá trị lớn nhất tại X[i] là n - k + 1
        X[i] = j;
        if (i == k) {
            in();
            cout << endl;
        } 
        else Try(i + 1);
       }
}
int main()
{
    cin >> n >> k;
    Try(1);
    return 0;
}