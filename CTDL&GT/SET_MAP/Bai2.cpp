// [SET MAP]. Bài 3. Phần tử riêng biệt
/*
Cho dãy số A[] gồm có N phần tử, bạn hãy trả lời các truy vấn để xác định xem phần tử X nào đó có nằm trong 
mảng hay không ? Bạn hayc thử giải bài này bằng 3 cách: Set, Map, Binary Search

** Input format:
- Dòng đầu tiên là số nguyên N
- Dòng thứ 2 gồm N số nguyên A[i]
- Dòng thứ 3 là số lượng truy vấn Q
- Q dòng tiếp theo mỗi dòng là một số nguyên X

** Output format:
- Đối với mỗi truy vấn in ra YES nếu phần tử X xuất hiện trong mảng, ngược lại in ra NO
*/
#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    

    set<int> se;
    for (int x : a) {
        se.insert(x);
    }
    

    int q; cin >> q;
    while(q--) {
        int x;
        cin >> x;
        if (se.find(x) != se.end()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}