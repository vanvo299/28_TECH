/*
[Graph]. Bài 4. Chuyển từ danh sách kề sang danh sách cạnh (Có hướng)

Đề: Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách kề 
này sang danh sách cạnh tương ứng

- Input: Dòng đầu tiên là số nguyên dương n, tương ứng với số đỉnh của đồ thị. N dòng tiếp theo mỗi dòng chứa nhiều
số nguyên, dòng thứ i tương ứng với các đỉnh trong danh sách kề của đỉnh i
- Output: In ra các cạnh trong đồ thị trên từng dòng, các cạnh được liệt kê tăng dần
*/
#include <bits/stdc++.h>
using namespace std;

void xuLy(int i, string s)
{
    stringstream ss(s);
    string tmp;
    vector<int> v;
    while(ss >> tmp) {
        int j = stoi(tmp);
        v.push_back(j);
    }
    sort(v.begin(), v.end());
    for (int j : v) {
        cout << i << ' ' << j << endl;
    }
}

int main()
{
    int n; cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        xuLy(i, s);
    }
    return 0;
}