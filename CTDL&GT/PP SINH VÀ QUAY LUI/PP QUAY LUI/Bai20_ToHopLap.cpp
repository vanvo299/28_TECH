/*
[Quay lui - Nhánh cận]. Bài 20. Tổ hợp lặp

Đề: Cho xâu kí tự S gồm N chữ cái khác nhau, hãy liệt kê tổ hợp lặp chập K của N kí tự trên và in ra theo thứ tự từ
điển tăng dần

*/
#include <bits/stdc++.h>
using namespace std;

int n, k;
string s, tmp = "";

void nhap()
{
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());
}
vector<string> res;

void Try(int index) 
{
    for (int j = index; j < n; j++) {
        tmp += s[j];
        if (tmp.size() == k) {
            cout << tmp << endl;
        }
        else {
            Try(j);
        }
        // backtrack
        tmp.pop_back();
    }
}

int main()
{
    nhap();
    Try(0);
    return 0;
}