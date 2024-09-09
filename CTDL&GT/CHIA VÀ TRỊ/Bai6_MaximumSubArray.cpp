/*
[Chia và trị]/ Bài 6. Maximmum Sub Array

Đề: Cho dãy số nguyên A[] gồm N phần tử, nhiệm vụ của bạn là tính tổng dãy con liên tiếp có tổng lớn nhất

*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll crossingSum(int a[], int left, int right, int mid)
{
    ll sumLeft = 0, maxSumLeft = 0;
    ll sumRight = 0, maxSumRight = 0;
    
    for (int i = mid; i >= left; i--) {
        sumLeft += a[i];
        maxSumLeft = max(maxSumLeft, sumLeft);
    }

    for (int i = mid + 1; i <= right; i++) {
        sumRight += a[i];
        maxSumRight = max(maxSumRight, sumRight);
    }
    return maxSumLeft + maxSumRight;
}

ll maxSum(int a[], int left, int right )
{
    if (left == right) return a[left];
    int mid = (left + right) / 2;
    return ({
        maxSum(a, left, mid);
        maxSum(a, mid + 1, right);
        crossingSum(a, left, right, mid);
    });
}
int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    cout << maxSum(a, 0, n - 1);
    return 0;
}