// [MẢNG 1 CHIỀU]. BÀI 4. Die Hard
/*
Bộ phim "Die hard" mới vừa được phát hành. Có n người tai phòng vé rạp chiếu phim đứng thành một hàng. 
Mỗi người trong số họ có một tờ tiền mệnh giá 100, 50 hoặc 25 rúp. Một vé "Die Hard" có giá 25 rúp. Nhân
viên đặt phòng có thể bán vé cho mỗi người và trả tiền thừa nếu ban đầu anh ta không có tiền và bán vé theo
đúng thứ tự mọi người trong hàng không ?
*/
#include <iostream>
using namespace std;

int cnt[1001];
int check(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        if (a[i] == 25) {
            cnt[25]++;
        }
        else if (a[i] == 50) {
            if (cnt[25] == 0) return 0;
            cnt[25]--;
            cnt[50]++;
        }
        else {
            if (cnt[25] >= 1 && cnt[50] >= 1) {
                cnt[25]--;
                cnt[50]--;
                cnt[100]++;
            }
            else if (cnt[25] >= 3) {
                cnt[25] -= 3;
                cnt[100]++;
            }
            else return 0;
        } 
    }
    return 1;
}
int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) {
        cin >> x;
    }

    if (check(a, n)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}