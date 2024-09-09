/*
MAP là container giúp lưu các phần tử theo cặp key, value (khóa - giá trị). Mỗi
giá trị của key sẽ ánh xạ sang một value tương ứng. So với Set thì Map thậm
chí còn mạnh mẽ và giải quyết được nhiều vấn đề hơn

**TÍNH CHẤT:
- Các key trong map là những giá trị riêng biệt, không có 2 key nào có giá trị giống nhau, value thì có thể trùng nhau.
- Các cặp phần tử trong map được sắp xếp theo thứ tự tăng dần của key
- Mỗi phần tử trong map thực chất là một pair, với first lưu key và second lưu value.

*/
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    map<int, int> mp;// pair<int, int>
    mp.insert({1, 2});
    mp.insert({3, 4});
    mp.insert({1, 4}); // trong map đã có key 1 rồi nên sẽ không thêm được cặp {1, 4} vào được nữa
    mp.insert({3, 2}); // tương tự như trên
    mp.insert({4, 1});

    // thêm cặp {5, 10}
    // mp[5] = 10; // syntax: mp[key] = value; 
    // mp[3] = 20; // thay đổi cặp {3, 4} trong map thành cặp {3, 20}

    // cout << mp.size() << endl;

    // cout << mp[1] << endl; // in ra giá trị của key 1 là 2
    // cout << mp[5] << endl;
    // cout << mp[4] << endl;


    // Duyệt map

    // range base for loop
    for (pair<int, int> it : mp) {
        cout << it.first << " " << it.second << endl;
    }
    
    cout << endl;

    //iterator
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        // cout << (*it).first << " " << (*it).second << endl;
        cout << it->first << " " << it->second << endl;
    }

    cout << endl;
    // thay bang auto cho tien
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << (*it).first << " " << (*it).second << endl;
    }

    
    return 0;
}