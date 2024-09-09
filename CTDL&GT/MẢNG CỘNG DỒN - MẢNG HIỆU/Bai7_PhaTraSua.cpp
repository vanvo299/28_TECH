/*
[Mảng cộng dồn - Mảng hiệu]. Bài 7. Pha trà sữa

Đề: Tèo mới lên đại học và kiếm được một công việc tại hàng trà sữa, có không quá 200000 cốc trà sữa xếp thành
1 hàng ngang, ban đầu mỗi cốc trà sữa có độ ngọt bằng 0. Tèo tiến hành liên tiếp N các thao tác, mỗi thao tác
anh ta sẽ thêm 1 gam đường vào cốc trà sữa từ vị trí L tới vị trí R. Sau cùng những cốc trà sữa có lượng
đường >= K gam được chuyển đi để phục vụ khách hàng. Có nhiều câu hỏi, mỗi câu hỏi yêu cầu bạn trả lời 
trong các cốc trà sữa thứ L tới thứ R có bao nhiêu cốc đạt chuẩn để bán cho khách hàng ?
*/

// Dung mang hieu

#include <iostream>
using namespace std;

using ll = long long;

int a[200005];
int f[200005];
// f[i] : so luong coc tra sua co luong duong >= k nam trong doan tu 1 toi i
int main()
{

    // khoi tao mang hieu de tang luong duong cho moi coc tra sua
    int n, k, q; cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        a[l] += 1;
        a[r + 1] -= 1;
    }

    // cong don mang hieu 
    for (int i = 1; i <= 200000; i++) {
        a[i] = a[i] + a[ i - 1];
    }

    // dem so coc tra sua thoa man
    int count = 0;
    for (int i = 1; i <= 200000; i++) {
        if (a[i] >= k) ++count;
        f[i] = count;
    }

    //
    while(q--) {
        int l, r; cin >> l >> r;
        cout << f[r] - f[l - 1] << endl; // O(1)
    }
    return 0;
}