/*
[QUEUE]. Bài 12. Minimum Operator

ĐỀ: Cho hai số nguyên dương S và T và hai thao tác (a), (b) dưới đây: Thao tác (a): Trừ S đi 1 (S = S - 1); Thao tác (b):
Nhân S với 2 (S = S * 2); Hãy dịch chuyển S thành T sao cho số lần thực hiện các thao tác (a), (b) là ít nhất. Ví dụ
với S = 2, T = 5 thì số các bước ít nhất để dịch chuyển S thành T thông qua 4 thao tác sau: Thao tác (a): 2 * 2 = 4;
Thao tác (b): 4 - 1 = 3; Thao tác (a): 3 * 2 = 6; Thao tác (b): 6 - 1 = 5;

Input Format: Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test; T dòng tiếp theo mỗi dòng ghi lại một bộ Test. Mỗi test là
một bộ đôi số S và T
Output: Đưa ra kết quả mỗi bộ Test

*/
#include <bits/stdc++.h>
using namespace std;

int convert(int s, int t)
{
    queue<pair<int, int>> Q; // pair<trạng thái đỉnh, số thao tác>
    Q.push({s, 0});
    set<int> se;
    se.insert(s);

    while(!Q.empty()) {
        pair<int, int> x = Q.front(); Q.pop();
        // Khi s đã biến đổi xong thành t => trả về số lần thao tác
        if (x.first == t) {
            return x.second;
        }
        // x.first = x.first - 1
        if (x.first > 1 && se.count(x.first - 1) == 0) {
            Q.push({x.first - 1, x.second + 1});
            se.insert(x.first - 1);
        }
        // x.first = x.first * 2
        if (x.first < t && se.count(x.first * 2) == 0) {
            Q.push({x.first * 2, x.second + 1});
            se.insert(x.first * 2);
        }
    }   
    return -1;
}
int main()
{
    int t; cin >> t;
    vector<int> res;
    while(t--) {
        int s, t; cin >> s >> t;
        res.push_back(convert(s, t));
    }
    cout << "So buoc bien doi cua cac test case lan luot la: " << endl;
    for (auto it : res) {
        cout << it << endl; 
    }
    return 0;
}