/*
[Quay lui - Nhánh cận]. Bài 23. Combination Sum 2

Đề: Cho 2 số nguyên dương N và K, bạn hãy liệt kê các tổ hợp K phần tử các số nguyên tố mà có tổng bằng N.
Mỗi tổ hợp chỉ tính 1 lần và được in ra theo thứ tự từ bé đến lớn, các tổ hợp cũng được liệt kê theo thứ tự từ
điển tăng dần. Nếu không tồn tại tổ hợp K phần tử thỏa mãn có tổng bằng N thì in ra NOT FOUND.
*/
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> res;
vector<int> tmp;

vector<int> prime; // vector để lưu các số nguyên tố từ 1 đến 500

bool ktNguyenTo(int n) 
{
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return n > 1;
}

void Try(int index, int sum) 
{
    for (int j = index; j <= prime.size(); j++) {
        tmp.push_back(prime[j]);
        sum += prime[j];
        if (sum == n && tmp.size() == k) {
            res.push_back(tmp);
        }
        else if (sum < n && tmp.size() < k) {
            Try(j + 1, sum);
        }
        // backtrack
        tmp.pop_back();
        sum -= prime[j];
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= 500; i++) {
        if (ktNguyenTo(i)) {
            prime.push_back(i);
        }
    } 
    Try(0, 0);
    sort(res.begin(), res.end());
    if (res.size() == 0) {
        cout << "NOT FOUND" << endl;
        return 0;
    }
    for (vector<int> tmp : res) {
        for (int j = 0; j < tmp.size(); j++) {
            cout << tmp[j];
            if (j != tmp.size() - 1) cout << " + ";
            else cout << " ";
        }
        cout << endl;
    }
    return 0;
}