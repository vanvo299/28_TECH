/*
[Mảng cộng dồn - Mảng hiệu]. Bài 8. PrefixPrefix


Đề: Cho mảng A[] có N phần tử và M thao tác, mỗi thao tác yêu cầu bạn tăng các phần tử ở vị trí L tới R của mảng
lên D đơn vị (1 <= L <= R <= N). Các thao tác này được đánh số từ 1 đến M, ngoài ra Tèo lại muốn thực hiện K truy 
vấn, mỗi truy vấn Tèo lại thực hiện các thao tác từ x tới y theo số thứ tự thao tác (1 <= x <= y <= M). Bạn hãy giúp
Tèo in ra mảng A[] sau truy vấn.

M: so luong thao tac
K: so luong truy van

- Input Format:
+ Dòng 1 là n, m, k
+ Dòng 2 là N số trong mảng a[]
+ m dòng tiếp theo mỗi dòng gồm 3 số l, r, d (được lưu lần lượt vào l[i], r[i], d[i])
+ k dòng tiếp theo mỗi dòng gồm 2 số x, y
6 5 2
1 7 5 2 8 7
2 6 5
1 5 1
1 6 1
2 6 4
2 5 4
2 5
2 4
=> output: 5 23 21 18 24 17 (mảng a sau khi truy vấn)
*/
#include <iostream>
using namespace std;

using ll = long long;

// a[maxn] : 
// l[maxn], r[maxn] : luu cac chi so left, right trong moi lan truy van
// val[maxn] : luu gia tri can tang len trong moi truy van
// diff[maxn] : mang hieu dung de dem moi truy van thuc hien bao nhieu lan
// query[maxn] : mang hieu cua cac truy van

/*
Các bước làm: 
- B1: Dựa vào mảng hiệu để xác định mỗi truy vấn được thực hiện bao nhiêu lần và lưu vào mảng diff 
- B2: Dựa vào số lần truy vấn ta sẽ nhân với số lần mỗi truy vấn thực hiện
- B3: Tính mảng cộng dồn của query và cộng với a[i] ban đầu thì ta có mảng a cần tìm sau truy vấn
*/
const int maxn = 1e5 + 5;

ll a[maxn], l[maxn], r[maxn], d[maxn];
ll diff[maxn], query[maxn];

int n, m, k;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> d[i];
    }

    for (int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;
        diff[x] += 1; diff[y + 1] -= 1;
    }

    for (int i = 1; i <= m; i++) {
        diff[i] += diff[i - 1];
        query[l[i]] += diff[i] * d[i];
        query[r[i] + 1] -= diff[i] * d[i];
    }

    for (int i = 1; i <= n; i++) {
        query[i] += query[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        cout << query[i] + a[i] << " ";
    }

    return 0;
}