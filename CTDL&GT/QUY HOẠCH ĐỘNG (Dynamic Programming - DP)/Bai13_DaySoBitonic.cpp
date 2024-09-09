/*
[DP]. Bài 13. Dãy số Bitonic

Đề: Một dãy số được gọi là Bitonic nếu nó được chia thành hai dãy đầu tăng dần và dãy tiếp
theo giảm dần. Nhiệm vụ của bạn là tìm tổng lớn nhất dãy con Bitonic của dãy số A[]. Ví
dụ với dãy A[] = {1, 15, 51, 45, 33, 100, 12, 18, 9} ta có kết quả là 194 tương ứng với dãy Bitonic
{1, 15, 51, 100, 18, 9}

*/

/*
- Cách làm:
+ Tạo tổng lớn nhất các phần tử tăng dần lưu vào F[]
+ Tạo tổng lớn nhất các phần tử giảm dần lưu vào G[]
+ Sau đó tính tổng dãy Bitonic bằng cách lấy F[] + G[] rồi trừ cho phần tử trùng
*/
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n; cin >> n;
    int a[n + 1], F[n + 1], G[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        F[i] = a[i];
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                F[i] = max(F[i], F[j] + a[i]);
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        G[i] = a[i];
        for (int j = n; j > i; j--) {
            if (a[j] < a[i]) {
                G[i] = max(G[i], G[j] + a[i]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, F[i] + G[i] - a[i]);
    }
    cout << res << endl;
    return 0;
}