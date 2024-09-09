/*
- Thuật toán sinh hoán vị
*/


#include <bits/stdc++.h>
using namespace std;

int n, a[100], final = 0;

void ktao()
{
    // khoi tao cau hinh dau tien
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
}

void sinh()
{
    int i = n - 1;
    while(i >= 1 && a[i] > a[i + 1]) {
        --i;
    }
    if (i == 0) {
        final = 1;
    }
    else {
        // di tim a[j] lon hon a[i] ma nho nhat
        int j = n;
        while(a[i] > a[j]) --j;
        swap(a[i], a[j]);
        sort(a + i + 1, a + n + 1); // ham sap xep phan phia sau i
        // reverse(a + i + 1, a + n + 1); // ham lat nguoc day phia sau i
    }
}

vector<vector<int>> res;
int main()
{
    cin >> n;
    ktao();
    while(!final) {
        vector<int> tmp;
        for (int i = 1; i <= n; i++) {
            tmp.push_back(a[i]);
        }
        res.push_back(tmp);
        sinh();
    }
    for (int i = 0; i <= res.size() - 1; i++) {
        for (int &x : res[i]) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0; 
}