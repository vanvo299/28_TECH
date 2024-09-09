/*
[Quay lui - Nhánh cận]. Bài 22. Combination Sum 1

Đề: Cho 2 số nguyên dương N và K, Bạn hãy liệt kê các tổ hợp K phần tử các số có 1 chữ số mà có tổng bằng N.
Mỗi tổ hợp chỉ tính 1 lần và được in ra theo thứ tự từ bé đến lớn, các tổ hợp cũng được liệt kê theo tứ tự từ 
điển tăng dần. Nếu không tồn tại tổ hợp K phần tử thỏa mãn có tổng bằng N thì in ra NOT FOUND.
*/
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> res;
vector<int> tmp;

void Try(int index, int sum)
{
    for (int j = index; j <= 9; j++) {
        tmp.push_back(j);
        sum += j;
        if (sum == n && tmp.size() == k) {
            res.push_back(tmp);
        } else if (sum < n && tmp.size() < k) {
            Try(j + 1, sum);
        }
        // backtrack
        tmp.pop_back();
        sum -= j;

    }
}
int main()
{
    cin >> n >> k;
    Try(1, 0);
    sort(res.begin(), res.end());
    if (res.size() == 0) {
        cout << "NOT FOUND" << endl;
        return 0;
    }
    for (vector<int>tmp : res) {
        for (int j = 0; j < tmp.size(); j++) {
            cout << tmp[j];
            if (j != tmp.size() - 1) {
                cout << " + ";
            } else cout << " ";
        }
        cout << endl;
    }
    return 0;
}