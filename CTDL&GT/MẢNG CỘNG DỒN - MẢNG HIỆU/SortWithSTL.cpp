/*
 ----Hàm sort trong thư viện STL---- (nằm trong thư viện algorithm)
 * Thư viện STL cung cấp 2 hàm sort:
 + sort: Hàm sort được cài đặt bằng intro sort (kết hợp của quicksort và heapsort)
 + stable_sort: Hàm stable_sort được cài đặt bằng thuật toán merge sort nên có thêm tính chất stable

*/

// TRONG SLIDE CŨNG CÓ
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// comparison function
// - trả về true nếu bạn muốn a đứng trước b sau khi sắp xếp
// - tra về false nêú bạn muốn b đứng trước a sau khi sắp xếp
bool comparison(int a, int b)
{
    if (abs(a) > abs(b)) return true; // tăng dần, ngược lại a < b thì sắp xếp giảm dần
    else return false;
}

int main()
{
    int n; cin >> n;
    // vector<int> a(n);
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // khi dùng mảng
    // sort(a, a + n); // sắp xếp tăng dần
    // sort(a, a + n, greater<int>()); // sắp xếp giảm dần, thêm tham số greater

    // khi dùng vector
    // sort(a.begin(), a.end()); // sắp xếp tăng dần
    // sort(a.begin(), a.end(), greater<int>()); // sắp xếp giảm dần
    

    sort(a, a + n, comparison); // sắp xếp theo ý mình
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}