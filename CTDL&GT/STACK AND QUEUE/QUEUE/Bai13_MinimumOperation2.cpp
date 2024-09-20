/*
[QUEUE]. Bài 13. Minimum operation 2

ĐỀ: Cho số tự nhiên và hai phép biến đổi (a), (b) dưới đây: + Thao tác (a): Trừ N đi 1 (N = N - 1). Ví dụ N = 17, thao tác
(a) biến đổi N = N - 1 = 16. + Thao tác (b): N = max(u, v) nếu u * v = N (u > 1, v > 1). Ví dụ N = 16, thao tác (b) có thể 
biến đổi N = max(2, 8) = 8 hoặc N = max(4, 4). Chỉ được phép sử dụng hai thao tác (a) hoặc (b), hãy biến đổi N 
thành 1 sao cho số các thao tác (a), (b) được thực hiện ít nhất. Ví dụ với N = 17, số các phép (a), (b) nhỏ nhất biến đổi 
N thành 1 là 4 bước như sau: - Thao tác (a): N = N - 1 = 17 - 1 = 16. - Thao tác (b): 16 = max(4, 4) = 4. - Thao tác (b): 
4 = max(2, 2) = 2. - Thao tác (a): 2 = 2 - 1 = 1.

-Input format: Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test. T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là
một số N
*/
#include <bits/stdc++.h>
using namespace std;

int convert(int s)
{
    queue<pair<int, int>> Q; // pair<trạng thái đỉnh, số thao tác>
    Q.push({s, 0});
    set<int> se;
    se.insert(s);

    while(!Q.empty()) {
        pair<int, int> x = Q.front(); Q.pop();
        // Khi s đã biến đổi xong thành t => trả về số lần thao tác
        if (x.first == 1) {
            return x.second;
        }
        // x.first = x.first - 1
        if (x.first > 1 && se.count(x.first - 1) == 0) {
            Q.push({x.first - 1, x.second + 1});
            se.insert(x.first - 1);
        }
        // x.first = max(u, v), u*v = x.first
        int n = x.first;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                int u = i, v = n / i;
                int tmp = max(u, v);
                if (se.count(tmp) == 0) {
                    Q.push({tmp, x.second + 1});
                    se.insert(tmp);
                }
            }
        }     
    }   
    return -1;
}
int main()
{
    int t; cin >> t;
    vector<int> res;
    while(t--) {
        int n; cin >> n;
        res.push_back(convert(n));
    }
    cout << "So buoc bien doi cua cac test case lan luot la: " << endl;
    for (auto it : res) {
        cout << it << endl; 
    }
    return 0;
}