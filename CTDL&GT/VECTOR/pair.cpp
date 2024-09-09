/* Trong C++, std::pair là một cấu trúc dữ liệu đặc biệt được cung cấp trong thư viện tiêu chuẩn của C++ (STL) 
trong <utility> để lưu trữ một cặp các đối tượng,
ví dụ như hai giá trị có các kiểu dữ liệu khác nhau hoặc giống nhau.
 */
#include <iostream>
#include <utility>
using namespace std;
int main()
{
    pair<int, int> p = {100, 200}; // hoac dung make_pair(100, 200)
    //  first second
    // p.first = 100;
    // p.second = 200;

    cout << p.first << ' ' << p.second << endl;
    return 0;
}
