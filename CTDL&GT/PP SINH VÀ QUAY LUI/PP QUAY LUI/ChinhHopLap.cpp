/*
- Sinh chỉnh hợp lặp chập K của N phần tử
*/
#include <bits/stdc++.h>
using namespace std;

int n, X[100], k, cnt = 0;

void in()
{
    for (int i = 1; i <= k; i++) {
        cout << X[i];
    }
}

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
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