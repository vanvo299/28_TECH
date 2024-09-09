/* SET: Set là một container cực kì mạnh mẽ trong thư viện STL của ngôn ngữ lập
trình C++, sử dụng thành thạo Set là một kỹ năng cơ bản mà bạn cần đạt
được. Set sẽ giúp code của các bạn trở nên tối ưu và ngắn gọn hơn rất nhiềU

** 2 tính chất quan trọng của set: 
- Set là một container mà mỗi phần tử trong đó là duy nhất, tức là sẽ không có 2 phần tử có giá trị giống
nhau tồn tại trong set.
- Các phần tử trong set được sắp xếp theo thứ tự tăng dần về giá trị số và tăng dần về thứ tự từ điển
nếu là xâu kí tự
*/
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;
using ll = long long;
int main()
{
    int a[] = {3, 1, 2, 2, 1, 4, 2};
    set<int> se(a, a + 7); // cách khác để đưa nhanh một mảng vào set

    // hàm insert
    // for (int x : a) {
    //     se.insert(x);
    // }
    // duyệt bằng cách thông thường
    for (int x: se) cout << x << " "; // output: 1 2 3 4

    cout << endl;

    // duyệt set dùng iterator (giống như vector)
    for (set<int>::iterator it = se.begin(); it != se.end(); ++it) {
        cout << *it << " "; // output: 1 2 3 4
    }

    cout << endl;
    // duyệt ngược (từ cuối về)
    for (auto it1 = se.rbegin(); it1 != se.rend(); ++it1) {
        cout << *it1 << " ";
    }

    cout << endl;
    // in ra phần tử nhỏ nhất trong set
    cout << *se.begin() << endl;
    // in ra phần tử lớn nhất trong set
    cout << *se.rbegin() << endl; // hoặc có thể in *se.endl() để tìm

    // find() (hàm tìm kiếm phần tử)
    // auto it = se.find(4);
    if (se.find(4) == se.end())
    {
        cout << "Khong tim thay !!!\n";
    } else cout << "Tim thay !!!\n";


    // hàm count (đếm số lần xuất hiện của 1 phần tử trong set)
    // nhưng đối với set thì mỗi phần tử chỉ xuất hiện 1 hoặc 0 lần, cho nên có thể dùng hàm count để thay thế hàm find

    // hàm erase (Xóa một phần tử trong set)
    // nếu xóa một phần tử không tồn tại trong set thì chương trình sẽ báo lỗi (Runtime error)
    auto it = se.find(3);
    it--; // iterator có thể dịch trái hoặc dịch phải (Lưu ý: ko dùng it += 2,3....)
    cout << *it << endl; // 2
    if (it != se.end()) se.erase(it);
    for (int x: se) cout << x << " ";
    cout << endl;


    /* MULTISET: Multiset tương tự như set nhưng có thể lưu nhiều phần tử có giá trị
    giống nhau, các phần tử này cũng được sắp xếp theo thứ tự tăng
    dần. Các hàm của multiset giống y hệt các hàm của set chỉ khác
    một chút ở hàm find, count, erase */

    multiset<int> s(a, a + 7);
    for (int x : s) cout << x << " "; //output: 1 1 2 2 3 4
    cout << endl;

    /*
    UNORDERED_DET tương tự như set, nó chỉ có thể lưu các phần tử đôi 
    một khác nhau nhưng lại không có thứ tự. Không có thứ tự tức là 
    các phần tử ở trong unordered_set sẽ xuất hiện một cách bất kì, 
    không phải là theo thứ tự bạn thêm phần tử vào
    */

   unordered_set<int> us(a, a + 7); // a[] = {3, 1, 2, 2, 1, 4, 2}
   for (int  x : us) cout << x << " "; // output: 4 2 1 3
    return 0;
}