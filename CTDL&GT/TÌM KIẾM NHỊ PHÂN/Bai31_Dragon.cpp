/*
[Sắp xếp - Tìm kiếm]. Bài 31. Dragon

Đề: Kirito đang bị mắc kẹt ở cấp độ của MMORPG mà anh ấy đang chơi hiện tại. Để tiếp tục trò chơi, anh ta phải
đánh bại tất cả n con rồng sống ở cấp độ này. Kirito và những con rồng có sức mạnh, được biểu thị bằng một số nguyên.
Trong cuộc độ sức giữa hai đối thủ, kết quả của cuộc đọ sức được quyết định bởi sức mạnh
của họ. Ban đầu, sức mạnh của Kirito bằng s.

Nếu Kirito bắt đấu đấu tay đôi với rồng thứ i (1 <= i <= n) và sức mạnh của Kirito không lớn hơn sức mạnh của rồng 
có sức mạnh là xi, thì Kirito thua trận đấu và chết. Nhưng nếu sức mạnh của Kirito lớn hơn sức mạnh 
của con rồng, thì anh ta sẽ đánh bại con rồng và được tăng thêm được mạnh theo là yi.

Kirito có thể chiến đấu với những con rồng theo bất kỳ thứ tự nào. Xác định xem liệu anh ta có thể chuyển
sang cấp độ tiếp theo của trò chơi hay không, tức là đánh bại tất cả những con rồng mà không bị thua một lần nào.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, s;
    cin >> n >> s;

    vector<pair<long long, long long>> vp;
    for (long long i = 0; i < n; i++){
        long long x, y;
        cin >> x >> y;
        vp.push_back({x, y});
    }

    sort(vp.begin(), vp.end());
    for (long long i = 0; i < n; i++) {
        if (s <= vp[i].first) {
            cout << "NO" << endl;
            return 0;
        } else {
            s += vp[i].second;
        }
    }
    cout << "YES" << endl;

    return 0;
}
