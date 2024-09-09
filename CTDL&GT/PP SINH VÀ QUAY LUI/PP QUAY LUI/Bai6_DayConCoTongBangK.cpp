/*
Bài 6. Dãy con có tổng bằng K
Cho dãy số A[] = (a1, a2, .., an) và số tự nhiên K. 
Hãy đưa ra tất cả các dãy con của dãy số A[] sao cho tổng các phần tử của dãy con đó đúng bằng K. 
Các phần tử của dãy số A[] được giả thuyết là nguyên dương và không có các phần tử giống nhau. 
Ví dụ với dãy con A[] = {5, 10, 15, 20, 25}, K = 50 ta có 3 dãy con {5, 10, 15, 20}, {5, 20, 25}, {10, 15, 25}.

*/
#include <bits/stdc++.h>
using namespace std;

int A[100], X[100], daXet[100];
int n, k, t, sum = 0;

// void in()
// {
//     cout << "{";
//     for (int i = 1; i <= n; i++) {
//         cout << A[i] << ", ";
//     }
//     cout << "}";
// }

void Try(int i, int pos) 
{
    for (int j = pos; j <= n; j++) {
        X[i] = A[j];
        sum += A[j];
        if (sum == k) {
            cout << '[';
            for (int l = 1; l <= i; l++) {
                cout << X[l] << ' ';
            }
            cout << "] ";
            cout << endl;
        }
        else Try(i + 1, j + 1);
        sum -= A[j];
    }
}
int main()
{
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> A[i];
        memset(daXet, 0, sizeof(daXet)); // khởi tạo tât cả các phần tử trong mảng daXet đều bằng 0
        sort(A + 1, A + n + 1);
        Try(1, 1);
        cout << endl;
    }
    return 0;
}