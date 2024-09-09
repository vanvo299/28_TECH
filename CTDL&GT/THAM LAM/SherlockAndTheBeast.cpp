/*
[Tham lam]. Sherlock and the Beast

Đề: Sherlock Holmes suspects his archenemy Professor Moriarty is once again plotting something diabolical.
Sherlock's companion, Dr. Watson, suggests Moriarty may be responible for MI6's recent issue with their
supercomputer, The Beast

Shortly after resolving to Investigate, Sherlock receives a note from Moriarty boasting about infecting The Beast
with a virus. He also gives him a clue; an integer. Sherlock determines the key to removing the virus is to 
find the largest Decent Number having that number of digits.

A Decent Number has the following properties:
1. Its digits can only be 3 and/or 5
2. The number of 3's it contains is divisible by 5
3. The number of 5's it contains is divisible by 3
4. It is the largest such number for its length.

Dịch: 
Sherlock Holmes nghi ngờ kẻ thù không đội trời chung của mình, Giáo sư Moriarty, một lần nữa đang âm mưu điều gì đó tàn ác. 
Người bạn đồng hành của Sherlock, Tiến sĩ Watson, gợi ý rằng Moriarty có thể chịu trách nhiệm về vấn đề gần đây của MI6 với
siêu máy tính của họ, The Beast.

Ngay sau khi quyết định điều tra, Sherlock nhận được một ghi chú từ Moriarty khoe khoang về việc đã nhiễm virus vào The Beast. 
Ông ta cũng đưa cho Sherlock một manh mối; một số nguyên. Sherlock xác định rằng chìa khóa để loại bỏ virus là tìm ra Số Đẹp lớn 
nhất có số chữ số bằng số nguyên đó.

Một Số Đẹp có các tính chất sau:

1. Các chữ số của nó chỉ có thể là 3 và/hoặc 5.
2. Số chữ số 3 trong số đó chia hết cho 5.
3. Số chữ số 5 trong số đó chia hết cho 3.
4. Đây là số lớn nhất có các tính chất trên cho độ dài của nó.
*/
#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    for (int a = 0; a <= n / 3; a++) {
        int tmp = n - 3 * a;
        if (tmp % 5 == 0) {
            for (int i = 1; i <= 3 * a; i++) cout << "5";
            for (int j = 1; j <= tmp; j++) cout << "3";
            cout << endl;
            return;
        } 
    }
    cout << "-1";

    // for (int b = 0; b <= n / 5; b++) {
    //     int tmp = n - 5 * b;
    //     if (tmp % 3 == 0) {
    //         for (int i = 1; i <= tmp; i++) cout << "5";
    //         for (int j = 1; j <= 5 * b; j++) cout << "3";
    //         cout << endl;
    //         return;
    //     }
    // }
    // cout << "-1";
}
int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        solve(n);
    }
    return 0;
}