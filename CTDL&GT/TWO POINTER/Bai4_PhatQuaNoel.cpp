/*
[Two Pointer]. Bài 4. Phát Quà Noel

Đề: Nhân dịp lễ giáng sinh 2022, 28Tech tổ chức phát quà cho các bạn nhỏ. Có N món quà được xếp thành hàng 
ngang, mỗi món quà đều có khối lượng cho trước. Tèo là một đứa trẻ cũng như nhiều đứa trẻ khác chỉ muốn
có càng nhiều quà càng tốt, không cần biết tới khối lượng của từng món quà nặng nhẹ ra sao.

Tuy nhiên chiếc túi của Tèo chỉ mang được trọng lượng tối đa là S. Bạn hãy xác định xem số lượng phần quà 
mà Tèo có thể lựa chọn tối đa là bao nhiêu để có thể không vượt quá trọng lượng tối đa mà cái túi có thể chịu
được. Ngoài ra trong lúc lựa chọn quá Tèo chỉ có thể chọn các phần quà xếp cạnh nhau mà thôi.

** Input format:
- Dòng đầu tiên là N và S.
- Dong thứ hai là trọng lượng của N phần quà.

*/

// Gợi ý : Bài toán tìm dãy con dài nhất có tổng <= S

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n, s; cin >> n >> s;
    int a[n];

    for (int &x : a) cin >> x;

    int left = 0, right = 0;
    ll sum = 0, ans = 0;
    

    for (right = 0; right < n; right++) {
        sum += a[right];
        // neu sum > s => thu hep doan [l, r] bang cach tang left
        while(sum > s) {
            sum -= a[left];
            ++left;
        }
        ans = right - left + 1;
    }

    cout << ans << endl;

    return 0;
}