/*
[Xâu ký tự]. Bài 18. Tạo email và mật khẩu.

Đề: Hiện tại trường đại học XYZ tổ chức cấp Email cho sinh viên mới nhập học. Email và mật khẩu sẽ được cấp dựa
trên tên của sinh viên và ngày sinh của sinh viên đó. Bạn hãy viết chương trình để cấp tài khoản theo yêu cầu
như sau, tên email được tạo bằng cách lấy tên của sinh viên và ghép với các chữ cái đầu tiên của họ và tên
đệm, tất cả ký tự trong email đều ở dạng in thường, ví dụ sinh viên có tên "Nguyen Van Long" sẽ được cấp 
email "longnv@xyz.edu.vn". Mật khẩu sẽ dựa trên ngày sinh của sinh viên đó, bằng cách ghép ngày tháng năm
lại với nhau, ví dụ sinh viên sinh ngày 27/04/2002 sẽ có mật khẩu là 2742002.

**Input format:
- Dòng đầu tiên là số lượng sinh viên cần cấp email N. N dòng tiếp theo, mỗi dòng gồm 2 phần họ tên và ngày
sinh, ngày sinh của sinh viên đã ở dạng chuẩn dd/mm/yyyy/ Giữa các từ có thể có nhiều dấu cách, từ cuối cùng
trong dòng là thông tin ngày sinh của sinh viên (xâu kí tự không có dấu cách chuẩn dd/mm/yyyy).

**Output format:
- Đối với mỗi sinh viên in ra thông tin trên 2 dòng, dòng thứ nhất là email, dòng thứ 2 là mật khẩu.

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        stringstream ss(s);
        vector<string> v;
        string word;
        while(ss >> word) {
            v.push_back(word);
        }

        int n = v.size();
        string email = v[n - 2];
        for (int i = 0; i < n - 2; i++) {
            email += v[i][0]; //  lay chu cai dau tien cua ho va ten dem
        }
        
        email += "@xyz.edu.vn";
        cout << email << endl;

        string dob = v[n - 1];
        stringstream ss2(dob);
        while(getline(ss2, word, '/')) {
            cout << stoi(word);
        }
        cout << endl;
    }
    return 0;
}