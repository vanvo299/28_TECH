/*
[Thuật toán sinh]. Bài 4. Xâu AB

Đề: Nhiệm vụ của bạn ở bài tập này là sinh ra các xâu chỉ gồm kí tự A và B theo thứ tự từ điển giảm dần
*/

#include <bits/stdc++.h>
using namespace std;

int n, a[100], final = 0;

void ktao() 
{
    for (int i = 1; i <= n; i++) {
        a[i] = 1;
    }
}

void sinh() 
{
    int i = n;
    while(i >= 1 && a[i] == 0) {
        a[i] = 1;
        --i;
    }
    if (i == 0) {
        final = 1;
    }
    else {
        a[i] = 0;
    }
}
int main()
{
    cin >> n;
    ktao();
    while(!final) {
    for (int i = 1; i <= n; i++) {
        cout << (char)(a[i] + 65);
        }
        cout << endl;
        sinh();
    }
    return 0;
}