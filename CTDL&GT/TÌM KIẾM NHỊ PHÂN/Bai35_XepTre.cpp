/*
[Sắp xếp - Tìm kiếm]. Bài 35. Xếp trẻ

Đề: Có n đứa trẻ muốn đi đu quay, và nhiệm vụ của bạn là tìm một chiếc thuyền gondola cho mỗi đứa trẻ. Mỗi
chiếc gondola có thể có một hoặc hai người trong đó và ngoài ra, tổng trọng lượng của một chiếc gondola 
không vượt quá x. Bạn biết cân nặng của mọi đứa trẻ. Số lượng thuyền gondola tối thiểu cần thiết cho 
trẻ em là bao nhiêu ?
*/
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, x, soLuongThuyen = 0;
    cin >> n >> x;
    int a[n];

    for (int &x : a) cin >> x;

    sort(a, a + n);
    int left = 0, right = n - 1;
    while(left <= right) {
        if (a[left] + a[right] <= x) {
            ++soLuongThuyen; ++left; --right;
        }
        else {
            --right;
            ++soLuongThuyen;
        }
    }
    cout << soLuongThuyen << endl;
    return 0;
}