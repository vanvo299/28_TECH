/*
[Tham lam]. Priyanka and Toys

Đề: Priyanka works for an international toy company that ships by container. Her task is to the determine the 
lowest cost way to combine her orders for shipping. She has a list of item weights. The shipping company has
a requirement that all items loaded in a container must weigh less than or equal to 4 units plus the weight of 
the minimum weight item. All items meeting that requirement will be shipped in one container.

What is the smallest number of containers that can be contracted to ship the items based on the given list of weights ?

For example, there are items with weights w = [1, 2, 3, 4, 5, 10, 11, 12, 13]. This can be broken into two
containers: [1, 2, 3, 4, 5] and [10, 11, 12, 13]. Each container will contain items weighing within 4 units of the
minimum weight item.

Dịch: Priyanka làm việc cho một công ty đồ chơi quốc tế vận chuyển bằng container. Nhiệm vụ của cô ấy là xác định cách 
kết hợp các đơn đặt hàng sao cho chi phí vận chuyển thấp nhất. Cô ấy có một danh sách các trọng lượng của các món hàng. 
Công ty vận chuyển yêu cầu rằng tất cả các món hàng được xếp vào một container phải có trọng lượng nhỏ hơn hoặc bằng 4 
đơn vị cộng với trọng lượng của món hàng nhẹ nhất. Tất cả các món hàng đáp ứng yêu cầu đó sẽ được vận chuyển trong một 
container.

Số lượng container ít nhất cần để vận chuyển các món hàng dựa trên danh sách trọng lượng đã cho là bao nhiêu?

Ví dụ, có các món hàng với trọng lượng w = [1, 2, 3, 4, 5, 10, 11, 12, 13]. Danh sách này có thể được chia thành hai 
container: [1, 2, 3, 4, 5] và [10, 11, 12, 13]. Mỗi container sẽ chứa các món hàng có trọng lượng trong vòng 4 đơn vị so 
với món hàng nhẹ nhất.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int w[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    sort(w, w + n);
    int ans = 1;
    int min_item = w[0];
    for (int i = 1; i < n; i++) {
        if (w[i] - min_item > 4) {
            ++ans;
            min_item = w[i];
        }
    }
    cout << ans << endl;
    return 0;
}