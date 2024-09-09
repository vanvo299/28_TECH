//// [SET MAP]. Bài 1. Phần tử riêng biệt
/*
Cho dãy số A[] gồm N phần tử, bạn hãy đếm xem trong mảng có bao nhiêu phần tử phân biệt ? 
Chú ý giải bài này với 3 cách: sử dụng set, map, sắp xếp
*/ 
#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
    int n; cin >> n;

    // dung map
    map <int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x] = 1;
    }
    cout << mp.size() << "\n\n";


    // dung set
    set<int> se;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        se.insert(x);
    }
    cout << se.size() << endl;
    
    return 0;
}
