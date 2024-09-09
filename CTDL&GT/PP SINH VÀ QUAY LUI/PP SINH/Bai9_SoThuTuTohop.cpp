/*
[Thuật toán sinh]. Bài 9. Số thứ tự tổ hợp.

Đề: Cho 2 số nguyên dương N và K và một tổ hợp chập K phần tử của N phần tử từ các số từu 1 tới N. Bạn hãy xác định
xem tổ hợp đã cho có số thứ tự bao nhiêu nếu xếp các tổ hợp chập K của N theo thứ tự ngược. Ví dụ N = 5, K = 3
và tổ hợp đã cho là {2, 3, 4} sẽ là tổ hợp có số thứ tự 4
*/
#include <bits/stdc++.h>
using namespace std;

int n, k, a[100], final = 0;

void ktao()
{
    for(int i = 1; i <= k; i++) {
        a[i] = i;
    }
}

void sinh() 
{
    int i = k;
    while(i >= 1 && a[i] == n - k + i) {
        --i;
    }
    if (i == 0) {
        final = 1;
    }
    else {
        ++a[i];
        for (int j = i + 1; j <= k; j++) {
            a[j] = a[j - 1] + 1;
        }
    }
}
vector<vector<int>> res;
int main()
{
    cin >> n >> k;
    int x[10];
    for (int i = 0; i < k; i++){
        cin >> x[i];
    }
    ktao();
    while(!final) {
        vector<int> tmp;
        for (int i = 1; i <= k; i++) {
            tmp.push_back(a[i]);
        }
        res.push_back(tmp);
        sinh();
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        // so sanh res[i] vs x
        bool check = true;
        for (int j = 0; j < k; j++) {
            if (x[j] != res[i][j]) {
                check = false;
                break;
            }
        }
        if (check) {
            cout << res.size() - i << endl;
        }
    }
    return 0;
}