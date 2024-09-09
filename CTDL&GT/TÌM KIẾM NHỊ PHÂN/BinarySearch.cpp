#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) {
        cin >> x;
    }
    sort(a, a + n);
    if(binary_search(a, a + n, 3)) {
        cout << "YES\n";
    } else cout << "NO\n";
    return 0;
}