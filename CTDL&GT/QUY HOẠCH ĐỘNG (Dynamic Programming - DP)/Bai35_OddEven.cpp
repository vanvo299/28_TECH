/*
[DP]. Bài 35. Odd-even

Đề: Bạn được cung cấp một mảng A gồm N giá trị nguyên dương. Một mảng con của mảng
này được gọi là mảng con Chẵn lẻ nếu số lượng các số nguyên lẻ trong mảng con này
bằng số lượng các số nguyên chẵn trong mảng con này.

Tìm số mảng con Lẻ-Chẵn cho mảng đã cho

*/
#include <bits/stdc++.h>
using namespace std;

int F[1001];

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    map<int, int> mp;
    // if (a[i] % 2 == 1) F[i] = F[i - 1] + 1;
    // else F[i] = F[i - 1] - 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int t = 0; // le - chan
    long long cnt = 0, tmp;
    mp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 1) t++;
        else t--;
        F[i] = t;
        cnt += mp[F[i]];
        // mp[F[i]] là số lần xuất hiện của giá trị F[i] tính đến thời điểm i
        mp[F[i]]++; 
    }
    cout << cnt << endl;
    return 0;
}