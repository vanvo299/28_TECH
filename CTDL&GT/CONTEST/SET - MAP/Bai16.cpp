// [SET MAP]. Bài 16. THI ĐẤU
/*
Cho thông tin các trận đấu của giải bóng đá Sunday League, nhiệm vụ của bạn là đối với mỗi động bóng hãy liệt
kê các đối thủ đã từng chạm trán. Danh sách các đội bóng được liệt kê theo thứ tự từ điển tăng dần và danh 
sách đối thủ của từng đội bóng cũng được liệt kê theo thứ tự từ điển 

Gợi ý: Dùng map<string, vector<string>> np; mỗi đội bóng sẽ dùng 1 vector để lưu lại danh sách các đối thủ
trong các trận bóng, sort danh sách đội bóng trước khi in ra kết quả.
- Hoặc có thể dùng map<string, set<string>> mp;

**Input Format:
- Dòng 1 là N: số trận bóng diễn ra
- N dòng tiếp theo mỗi dòng gồm thông tin của 1 trận đấu theo cú pháp X - Y, trong đó đội X thi đấu với đội Y

**Outpur format:
- In ra kết quả của bài toán theo mẫu
*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

// LƯU Ý: trước getline mà là cin thì phải có cin.ignore();


int tim(string s, char x)
{
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == x) return i;
    }
    return 0;
}
int main()
{
    int n; cin >> n;
    cin.ignore();
    map<string, multiset<string>> mp;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int pos = tim(s, '-');
        string t1 = s.substr(0, pos - 1);
        string t2 = s.substr(pos + 2);

        mp[t1].insert(t2);
        mp[t2].insert(t1);
    }

    cout << endl;
    
    for (auto it : mp) {
        cout << it.first << " : ";
        int i = 0;
        for (auto x : it.second) {
            cout << x;
            if (i < it.second.size() - 1) cout << ", ";
            i++;
        }
        cout << endl;
    }

    return 0;
}