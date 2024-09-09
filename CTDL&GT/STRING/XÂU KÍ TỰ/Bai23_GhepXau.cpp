/*
[Xâu ký tự]. Bài 23. Ghép xâu

Đề: Cho các từ chỉ bao gồm chữ cái in hoa và in thường, bạn được yêu cầu ghép các từ này lại với nhau sao cho từ
được ghép lại sau cùng có thứ tự từ điển lớn nhất.

*/
#include <bits/stdc++.h>
using namespace std;

// nối các xâu lại và kiểm tra xem cách nối nào có thứ tự từ điển lớn nhất rồi in ra

bool cmp(string u, string v)
{
    string uv = u + v;
    string vu = v + u;
    return uv > vu;
}

int main()
{
    int n; cin >> n;
    string a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++){
        cout << a[i];
    }
    return 0;
}