/*
[Tham lam]. Mark and Toys

Đề: Mark and Jane are very happy after having their first child. Their son loves toys, so Mark wants to buy some.
There are a number of different toys lying in front of him, tagged with their prices. Mark has only a certain
amount to spend, and he wants to maximize the number of toys he buys with this money. Given a list of toy
prices and an amount to spend, determine the maximum number of gifts he can buy.

Dịch: Mark và Jane rất hạnh phúc sau khi có đứa con đầu lòng. Con trai của họ rất thích đồ chơi, vì vậy Mark muốn 
mua một số đồ chơi. Có nhiều loại đồ chơi khác nhau trước mặt anh ấy, được gắn thẻ với giá của chúng. Mark chỉ có 
một số tiền nhất định để chi tiêu, và anh ấy muốn mua được nhiều đồ chơi nhất có thể với số tiền này. Được cung cấp 
danh sách giá của đồ chơi và số tiền để chi tiêu, hãy xác định số lượng đồ chơi tối đa mà anh ấy có thể mua.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    int a[n];

    for (int &x : a) cin >> x;
    sort(a, a + n);

    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum <= k) {
            cnt++;
        } else break;
    }
    cout << cnt << endl;
    return 0;
}