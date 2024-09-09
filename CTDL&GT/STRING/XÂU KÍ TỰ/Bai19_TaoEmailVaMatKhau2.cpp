/*
[Xâu kí tự]. Bài 19. Tạo email và mật khẩu 2

Đề: Trường đại học ABC tổ chức cấp email cho sinh viên mới nhập học. Email và mật khẩu sẽ được cấp dựa trên 
tên của sinh viên và ngày sinh của sinh viên đó. Bạn hãy viết chương trình để cấp tài khoản theo yêu cầu
như sau, tên email được tạo bằng cách lấy tên của sinh viên và ghép với các chữ cái đầu tiên của họ và tên
đệm tất cả các kí tự trong email đều ở dạng in thường, ví dụ sinh viên có tên "Nguyen Van Long" sẽ được cấp
email "longnv@xyz.edu.vn"

- Mật khẩu sẽ dựa trên ngày sinh của sinh viên đó, bằng cách ghép ngày tháng năm lại với nhau, ví dụ sinh 
viên sinh ngày 27/04/2002 sẽ có mật khẩu là 2742002. Ngoài ra sẽ có trường hợp sinh viên bị trùng
tên email, ví dụ, sinh viên "Nguyen Van Long" sẽ được cấp email "longnv@xyz.edu.vn", sinh vien "Ngo
Van Long" cũng sẽ được cấp email "longnv@xyz.edu.vn", vì thế nhà trường quy định, theo thứ tự tên trong 
danh sách, nếu email được cấp của sinh viên hiện tại đã được cấp cho một sinh viên trước đó thì thêm số
thứ tự vào tên email.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m; cin >> m;
    cin.ignore();
    map<string, int> mp;
    for (int i = 0; i < m; i++) {
        string s;
        getline(cin, s);
        vector<string> v;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        stringstream ss(s);
        string word;
        while(ss >> word) {
            v.push_back(word);
        }

        int n = v.size();
        string email = v[n - 2];
        for (int i = 0; i < n - 2; i++) {
            email += v[i][0];
        }
        mp[email]++;
        if (mp[email] == 1) {
            cout << email << "@xyz.edu.vn\n";
        } else cout << email << mp[email] << "@xyz.edu.vn\n";

        string dob = v[n - 1];
        stringstream ss2(dob);
        while(getline(ss2, word, '/')) {
            cout << stoi(word);
        }
        cout << endl;
    }
    return 0;
}