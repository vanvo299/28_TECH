// [SET MAP]. Bài 17. ĐIỂM TRUNG BÌNH
/*
Cho thông tin điểm thi của các môn học của các sinh viên, hãy tính điểm trung bình của sinh viên đó và in
ra màn hình. Điểm trung bình được tính bằng cách lấy tổng hệ số điểm và số tín chỉ chia cho tônge số tín chỉ. Ví
dụ sinh viên X học môn A 2 tín chỉ và có điểm là 5, môn B 3 tín chỉ và có điểm là 4 thì điểm trung bình được 
tính = (2 * 5 + 3 * 4) / (2 + 3)

**Input format:
- Gồm nhiều dòng, mỗi dòng gồm 3 thông tin: Tên sinh viên (có 1 từ), số tín chỉ và điểm số tương ứng. Dữ
liệu đảm bảo không có 2 sinh viên có cùng tên
*/
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double dtb(vector<pair<int, int>> v)
{
    int sum1 = 0, sum2 = 0;
    for (auto it : v) {
        sum1 += it.first * it.second;
        sum2 += it.first;
    }
    return (double) sum1 / sum2;
}
int main()
{
    map<string, vector<pair<int, int>>> mp;

    string ten;
    while(cin >> ten) {
        int tinChi; cin >> tinChi;
        int diem; cin >> diem;

        mp[ten].push_back({tinChi, diem});
    }

    for (auto it = mp.rbegin(); it != mp.rend(); ++it)
    {
        cout << (*it).first << " : ";
        cout << fixed << setprecision(2) << dtb(it->second) << endl;
    }

    return 0;
}
