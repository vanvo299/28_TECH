/*
[DP]. Bài 29. Equal set

Đề: Nhiệm vụ của bạn là đếm số cách các số 1,2,...,n có thể chia thành hai tập có tổng bằng 
nhau. Các phần tử trong tập không xét đến thứ tự. Ví dụ , nếu n = 7, có 4 nghiệm:
{1,3,4,6} và {2,5,7}, {1,2,5,6} và {3,4,7}, {1,2,4,7} và {3,5,6}, {1,6,7} và {2,3,4,5}

- In ra kết quả sau khi chia dư với 10^9 + 7
*/

#include <bits/stdc++.h>
using namespace std;

int F[1001];

int main()
{
    int n; cin >> n;
    int mod = 1e9 + 7;
    int Sum = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        Sum += i;
    }
    int s = Sum / 2;
    if (s % 2 != 0) {
        cout << "0" << endl;
        return 0;
    } 
    F[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= 1; j--) {
            if (j >= i) {
                F[j] += F[j - i];
                // i = n, j = s
                if (i == n && j == s) {
                    res = F[j - i];
                }
            }
            F[j] %= mod;
        }
    }
    cout << res;
    return 0;
}