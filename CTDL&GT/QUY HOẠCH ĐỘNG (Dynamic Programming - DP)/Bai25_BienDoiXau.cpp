/*
[DP]. Bài 25. Biến đổi xâu

Đề: Cho hai xâu kí tự str1, str2 bao gồm các ký tự in thường và các thao tác dưới đây: Insert:
chèn một ký tự bất kỳ vào str1. Delete: loại bỏ một ký tự bất kỳ trong str1. Replace: thay
một ký tự bất kỳ trong str1. Nhiệm vụ của bạn là đếm số các phép insert, delete, replace 
ít nhất thực hiện trên str1 để trở thành str2.

*/
#include <bits/stdc++.h>
using namespace std;

int F[505][505];

int main()
{
    string s1, s2; cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    s1 = "0" + s1;
    s2 = "0" + s2;

    for (int i = 1; i <= n; i++) F[i][0] = i;
    for (int j = 1; j <= m; j++) F[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i] != s2[j])
                F[i][j] = min({F[i - 1][j], F[i][j - 1], F[i - 1][j - 1]}) + 1;
                // F[i - 1][j] + 1: thực hiện một phép xóa.
                // F[i][j - 1] + 1: thực hiện một phép chèn.
                // F[i - 1][j - 1] + 1: thực hiện một phép thay thế.
            else 
                F[i][j] = F[i - 1][j - 1];
        }
    }
    cout << F[n][m];
    return 0;
}