// [MẢNG 1 CHIỀU]. BÀI 5. Gửi thư
/*
Tất cả các thành phố của LineLand đều nằm trên truc tọa độ Õ. Do đó mỗi thành phố
được liên kêt với vị trĩi - tọa độ trên trục Ox. Không có hai thành phố được đặt tại một
điểm. Cư dân Lineland thích gửi thư cho nhau. Một người chỉ có thể gửi thư nếu người 
nhận số ở một thành phố khác. Chi phí gửi thư chính xác bằng khoảng cách giữa thanh
phố của người gửi và thành phố của người nhận. Đối với mỗi thành phó, hãy tính hai giá
trị mini và maxi, trong đó mini là chi phí tối thiểu để gửi thư từ thành phố thứ i đến một
thành phố khác và maxi là chi phí tối đa để gửi thư từ thành phố thứ i đến một số thành phố khác.

**Input format: Dòng đầu tiên là số nguyên dương n. Dòng thứu hai chứa chuỗi n số nguyên khác nhau x1, x2, ...., xn
(trong đó xi là tọa độ x của thành phố thứ i. Tất cả các xi là khác biệt và theo thứ tự tăng dần)
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for(int &x : a) {
        cin >> x;
    }

    cout << a[1] - a[0] << " " << a[n - 1] - a[0] << endl;
    for (int i = 1; i < n - 1; i++) {
        int mini  = min(a[i] - a[i - 1], a[i + 1] - a[i]);
        int maxi = max(a[i] - a[0], a[n - 1] - a[i]);
        cout << mini << " " << maxi << endl;
    }

    cout << a[n - 1] - a[n - 2] << " " << a[n - 1] - a[0] << endl;
    return 0;
}
