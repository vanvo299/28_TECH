// [SET MAP]. Bài 8: Lớn nhất, nhỏ nhất
/*
Cho mảng A[] gồm N phần tử, có 4 loại thao tác:
- Thao tác 1: Thêm phần tử X vào mảng
- Thao tác 2: Xóa mọi giá trị X khỏi mảng nếu X tồn tại trong mảng
- Thao tác 3: Tìm phần tử nhỏ nhất trong mảng
- Thao tác 4: Tìm phần tử lớn nhất trong mảng

** Input format:
- Dòng 1 gồm N: Số lượng phần tử ban đầu trong mảng A[]
- Dòng 2 gồm N phần tử ban đầu của mảng A[]
- Dòng 3 gồm số lượng thao tác Q
- Q dòng tiếp theo mỗi dòng mô tả 1 thao tác, trong đó nếu là thao tác 1 và 2 thì có thêm phần tử X

**Ouput format:
In kết quả với thao tác 3 và 4
*/
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    set <int> s;
    int n; cin >> n;
    int a[n];
    for (int &x : a) {
        cin >> x;
        s.insert(x);
    }
    int q; cin >> q;

    while(q--) {
        int thaoTac; cin >> thaoTac;
        
        if (thaoTac == 1) {
            int x; cin >> x;
            s.insert(x);
        }
        else if (thaoTac == 2) {
            int x; cin >> x;
            if (s.find(x) != s.end()) {
                s.erase(x);
            }
        }
        else if (thaoTac == 3) {
            cout << *s.begin() << endl;
        }
        else if(thaoTac == 4) {
            cout << *s.rbegin() << endl;
        }
    }
    return 0;
}
