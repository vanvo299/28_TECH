/*
[Two Pointer]. Bài 3. 28Tech_Numer_Of_Equal

Đề: Cho 2 mảng A[] và B[] có N và M phần tử đã được sắp xếp theo thứ tự tăng dần, nhiệm vụ của bạn là hãy đếm
xem trong 2 mảng tồn tại bao nhiêu cặp i, j sao cho A[i] = B[j]
*/

#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    int n, m; cin >> n >> m;
    int a[n], b[m];

    for (int &x : a) cin >> x;
    for (int &y : b) cin >> y;

    int i = 0, j = 0;
    ll ans = 0;

    while(i <  n && j < m) {
        if (a[i] == b[j]) {
            int count1 = 0;
            while(a[i] == b[j]) {
                ++count1;
                ++i;
            }
            int count2 = 0;
            while(a[i - 1] == b[j]) {
                ++count2;
                ++j;
            }
            ans += 1ll * count1 * count2;
        } 
        else if (a[i] < a[j]) ++i;
        else ++j;
    }

    cout << ans << endl;
    return 0;
}