/*
[Graph]. Bài 2. Chuyển từ danh sách kề sang danh sách cạnh (Vô hướng)

Đề: Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách kề 
này sang danh sách cạnh tương ứng

- Input: Dòng đầu tiên là số nguyên dương n, tương ứng với số đỉnh của đồ thị. N dòng tiếp theo mỗi dòng chứa nhiều
số nguyên, dòng thứ i tương ứng với các đỉnh trong danh sách kề của đỉnh i

*/
#include <bits/stdc++.h>
using namespace std;


void xuLy(int i, string s)
{
    stringstream ss(s);
    string tmp;
    while(ss >> tmp) {
        int j = stoi(tmp);
        if (j > i) cout << i << " " << j << endl;
    }
}
int main()
{
    int n; cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin , s);
        xuLy(i, s);
    }
    return 0;
}