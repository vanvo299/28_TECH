/*
[Tham lam]. Jim and the orders

Đề: Jim's burger has a line of hungry customers. Orders vary in the time it takes to prepare them. Determine the 
order the customers receive their orders. Start by numbering each of the customers from 1 to n, front of the
line to the back. You will then be given an order number and a preparation time for each customer.

The time of delivery is calculated as the sum of the ordder number and the preparation time. if two orders are 
delivered at the same time, assume they are delivered in ascending customer number order.

Dịch:
Cửa hàng burger của Jim có một hàng dài khách hàng đang đói. Các đơn đặt hàng có thời gian chuẩn bị khác nhau. 
Hãy xác định thứ tự mà khách hàng nhận được đơn hàng của họ. Bắt đầu bằng cách đánh số mỗi khách hàng từ 1 đến n, 
từ đầu hàng đến cuối hàng. Sau đó, bạn sẽ được cung cấp số thứ tự đơn hàng và thời gian chuẩn bị cho mỗi khách hàng.

Thời gian giao hàng được tính bằng tổng của số thứ tự đơn hàng và thời gian chuẩn bị. Nếu hai đơn hàng được giao cùng 
một lúc, giả sử chúng được giao theo thứ tự tăng dần của số thứ tự khách hàng.
*/
#include <bits/stdc++.h>
using namespace std;

struct customer {
    int id, order_time, prepare_time;
};

int main()
{
    int n;
    cin >> n;
    customer a[n];
    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
        cin >> a[i].order_time >> a[i].prepare_time;
    }
    stable_sort(a, a + n, [](customer x, customer y)->bool {
        return x.order_time + x.prepare_time < y.order_time + y.prepare_time;
    });
    for (int i = 0; i < n; i++) {
        cout << a[i].id << ' ';
    }
    return 0;
}