#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> v; // empty
    int n; cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int x : v) cout << x << ' ';
    cout << endl;

    // VECTOR ITERATOR
    //  v = {1,2,3,4,5}
    vector<int>::iterator it = v.begin();
    cout << *it << endl; // *it đang trỏ đến phần tử đầu tiên của vector
    it++; // dịch iterator sang phải 1 phần tử  
    cout << *it << endl;

    // Duyệt các phần tử trong vector theo iterator
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    // chèn và xóa phần tử vào vector ở vị trí bất kì trong vector
    v.insert(v.begin() + 2, 100);
    v.erase(v.begin() + 3); // 
        for (it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }

    // một số hàm khác đọc thêm trong slide
    return 0;
}