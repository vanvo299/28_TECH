/*
[Xâu kí tự]. Bài 16. Chuẩn hóa tên 1

Đề: Cho một xâu là tên người chỉ bao gồm các kí tự là chữ cái và dấu cách, giữa các từ trong câu có thể tồn tại
nhiều dấu cách hãy chuẩn hóa tên người bằng cách viết hao chữu cái đầu tiên của từng từ và viết thường các
chữ cái còn lại. Xâu tiếp theo là ngày sinh của người này, bao gồm ngày tháng năm phân cách nhau bằng dấu
"/", hãy chuẩn hóa ngày sinh của người này về đúng dạng dd/mm/yyyy

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string name;
    getline(cin, name);
    string dob; cin >> dob;
    string new_name = "";
    stringstream ss(name);
    string word;
    while(ss >> word) {
        new_name += toupper(word[0]);
        for (int j = 1; j < word.size(); j++) {
            new_name += tolower(word[j]);
        }
        new_name += " ";
    }
    new_name.pop_back();
    
    cout << new_name << endl;
    stringstream ss1(dob);
    int count = 0;
    while(getline(ss1, word, '/')) {
        ++count;
        cout << setfill('0') << setw(2) << stoi(word);
        if (count != 3) cout << '/';
    }
    return 0;
}