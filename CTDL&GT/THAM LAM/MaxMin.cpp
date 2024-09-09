/*
[Tham lam]. Max Min

Đề: You will be given a list of integers arr and a single integer k. You must create an array of length k from
elements of arr such that its unfairness is minimized. Call that array arr'. Unfairness of an array is calculated
as 
                        max(arr') - min(arr')
Where:
- max denotes the largest integer in arr'
- min denotes the smallest integer in arr'

Dịch:
Bạn sẽ được cung cấp một danh sách các số nguyên arr và một số nguyên k. Bạn phải tạo một mảng có độ dài k từ các phần tử 
của arr sao cho độ chênh lệch của nó được giảm thiểu. Gọi mảng đó là arr'. Độ chênh lệch của một mảng được tính như sau:

                    max(arr') - min(arr')
Ở đây:

max biểu thị số nguyên lớn nhất trong arr'
min biểu thị số nguyên nhỏ nhất trong arr'
*/

// Dùng cửa sổ trượt (siding window)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;

    sort(a, a + n);
    long long ans = 1e18;
    for (int i = 0; i <= n - k; i++) {
        ans = min(ans, 0ll + a[i + k - 1] - a[i]);
    }
    cout << ans << endl;
    return 0;
}