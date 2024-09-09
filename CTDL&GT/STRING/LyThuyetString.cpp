/*

------------------LÝ THUYẾT SƠ LƯỢC VỀ STRING------------------------------------

I. String là lớp để xử lí xâu kí tự trong ngôn ngữ lập trình C++. Các bạn có thể nghĩ xâu như một mảng kí tự nhưng có thể
mở rộng, thu hẹp và hỗ trợ rất nhiều hàm xử lí xâu thông dụng.
- Cú pháp khai báo: string <name_string>; 
- VD: string s;

II. Các hàm thông dụng
1. Hàm size và hàm length
- Cả hai hàm này đều dùng để xác định chiều dài xâu, hay nói cách khác là số kí tự xuất hiện trong xâu.
VD: string s = "Luong Van Vo";
    cout << s.size() << endl;
    cout << s.length() << endl;

2. Duyệt xâu
- Có nhiều cách duyệt xâu, dùng for bth, range base for, iterator
- VD: 
string s = "ngon ngu lap trinh java";
** For
for (int i = 0; i < s.size(); i++) {
    cout << s[i] << " ";
}

** Range base for
for (char x : s) cout << x << " ";

** Iterator
for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it;
}

3. Hàm push_back và pop_back
- Tương tự như vector thì string cũng hỗ trợ thêm 1 phần tử vào cuối hay xóa 1 phần tử ở cuối xâu. Ở đây các phần tử của string
chính là kiểu char vì thế các bạn chỉ có thể push_back từng kí tự một.
- VD:
string s = "28tech";
s.push_back('@');
cout << s << endl;
s.pop_back();
cout << s << endl;

4. Hàm insert
- Bạn có thể chèn 1 xâu kí tự vào vị trí bất kì trong xâu ban đầu. Bạn chỉ cần cung cấp chỉ số cần chèn và xâu cần chèn cho 
hàm này
- VD: 
string s = "28tech";
s.insert(2, "@@@@"); // chèn xâu vào sau chỉ số 2
cout << s << endl;

5. Hàm erase
- Bạn có thể chỉ rõ chỉ số bắt đầu xóa kí tự và số lượng kí tự muốn xóa.
- VD:
string s = "28@@@tech";
s.erase(2, 3); // Xóa 3 kí tự từ chỉ số 2
cout << s << endl;
s.erase(2); // xóa mọi kí tự từ chỉ số 2
cout << s << endl;

6. Hàm find
- Giả sử bạn cần kiểm tra sự tồn tại của xâu con t trong xâu s. Hàm find trả về chỉ số đầu tiên của xâu t trong xâu s nếu s
có chứa t, ngược lại hàm này trả về giá trị string::npos
- VD:
string s = "28tech tech";
string t = "28tech";
if (s.find() != string::npos) {
    cout << "FOUND\n";
} else cout << "NOT FOUND\n";

III. Nhắc lại các hàm kiểm tra kí tự
*** Các hàm có sẵn trong thư viện <ctype.h>
- isdigit(char c) : Kiểm tra chữ số
- islower(char c) : kiểm tra chữ in thường
- isupper(char c) : kiểm tra chữ in hoa
- isalpha(char c) : kiểm tra chữ cái
- int tolower(char c) : chuyển thành chữ in thường // transform(s.begin(), s.end(), s.begin(), ::tolower);
- int toupper(char c) : chuyển thành chữ in hoa    // transform(s.begin(), s.end(), s.begin(), ::toupper);

*** Hàm chuyển từ xâu thành số : 
- stoi(s) : chuyển thành số nguyên
- stoll(s) : chuyển thành số nguyên kiểu long long
- ......
VD: string s = "123456";
    int n = stoi(s); // string to integer
    // chuỗi s phải toàn là số

// build ham chuyen chuoi thanh so kieu long long
long long my_stoll(string s)
{
    long long res = 0;
    for (int i = 0; i < s.size(); i++) {
        res = res * 10 + (s[i] - '0);
    }
    return res;
}
*** Hàm chuyển từ số thành xâu :
- to_string(n);
VD: int n = 123456;
    string s = to_string(n); // chuyển số thành xâu

// build ham chuyen so thanh xau
string my_tostring(long long n)
{
    string res = "";
    while(n != 0) {
        res += (n % 10 + '0');
    }
    return res;
}


*** Hàm lật ngược xâu: reverse(s.begin(), s.end());
*/