/*
[Quay lui - Nhánh cận]. Bài 19. Dãy con có tổng lẻ

Đề: Cho mảng A[] gồm N phần tử, liệt kê các tập con (giữ đúng thứ tự trước sau) của mảng A[] có tổng các phần tử
là số lẻ, mỗi phần tử chỉ được lấy 1 lần. Chú ý nếu 2 tập hợp chứa 2 phần tử có giá trị giống nhau nhưng ở vị trí
khác nhau thì được tính 2 tập hợp khác nhau. 
*/

// Quay lui trên mảng 
#include <bits/stdc++.h>
using namespace std;

int n, a[100], X[100];
void nhap() 
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

vector<vector<int>> res;

void Try(int i, int index, int sum)
{
    for (int j = index; j < n; j++) {
        sum += a[j];
        X[i] = a[j];
        if (sum % 2 == 1) {
            vector<int> tmp(X + 1, X + i + 1);
            res.push_back(tmp);
        }
        Try(i + 1, j + 1, sum);
        // backtrack
        sum -= a[j];
    }
}
int main()
{
    nhap();
    Try(1, 0, 0);
    if (res.size() == 0) {
        cout << "NOT FOUND\n";
        return 0;
    }
    sort(res.begin(), res.end());
    for (vector<int> tmp: res) {
        for (int x : tmp) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}