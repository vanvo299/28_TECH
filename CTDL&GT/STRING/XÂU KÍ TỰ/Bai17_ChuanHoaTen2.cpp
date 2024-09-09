/*
[Xâu kí tự]. Bài 17. Chuẩn hóa tên 2

Đề: Cho một xâu là tên người chỉ bao gồm các kí tự là chữ cái và dấu cách, giữa các từ trong câu có thể tồn tại
nhiều dâu cách, hãy chuẩn hóa tên người theo 2 mẫu được yêu cầu trước. Xem output để rõ hơn về cách chuẩn hóa

**Input: 
- hoang    diNH  NaM

**Output format:
- Hoang Dinh, NAM
- NAM, Hoang Dinh
*/

#include <bits/stdc++.h>
using namespace std;

void chuanHoa(string &s)
{
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
}


int main()
{
    string s;
    vector<string> v;
    while(cin >> s) {
        v.push_back(s);
    }

    for (char &x : v[v.size() - 1]) {
        x = toupper(x);
    }

    for (int i = 0; i < v.size() - 1; i++) {
        chuanHoa(v[i]);
    }

    for (int i = 0; i < v.size() - 1; i++) {
        if (i != v.size() - 2) cout << v[i] << " ";
        else if (i == v.size() - 2) cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << endl;

    cout << v[v.size() - 1] << ", ";
    for (int i = 0; i < v.size() - 1; i++) {
        if (i != v.size() - 2) cout << v[i] << " ";
        else if (i == v.size() - 2) cout << v[i];
    }
    return 0;
}