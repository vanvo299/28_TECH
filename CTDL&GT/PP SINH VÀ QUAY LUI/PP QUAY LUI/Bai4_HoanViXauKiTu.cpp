/*
Bài 4. Hoán vị xâu kí tự 
Cho xâu ký tự S bao gồm các ký tự in hoa khác nhau. Hãy đưa ra tất cả các hoán vị của xâu ký tự S.
 Ví dụ S=”ABC” ta có kết quả {ABC ACB BAC BCA CAB CBA}. 

*/
#include <bits/stdc++.h>
using namespace std;

int n, X[100], daXet[100];
string s = "";

void in() 
{
    for (int i = 1; i <= n; i++) {
        cout << (char)(X[i] + 64);
    }
}

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (daXet[j] == 0) {
            X[i] = j;
            daXet[j] = 1;
            if (i == n) {
                in();
                cout << ' ';
            }
            else Try(i + 1);
            daXet[j] = 0;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        n = s.length();
        Try(1);
    }
    return 0;
}