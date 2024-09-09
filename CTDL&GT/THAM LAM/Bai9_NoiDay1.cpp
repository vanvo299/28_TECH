/*
[Tham lam]. Bài 9. Nối dây 1

Đề: Cho N sợi dây, biết chi phí nối 2 sợi dây là tổng độ dài của 2 sợi dây đó. Nhiệm vụ của bạn là nối N sợi dây này
thành 1 sao cho chi phí nối dây là nhỏ nhất
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	//  Hàng đợi ưu tiên 
	priority_queue<int, vector<int>, greater<int>> Q;
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		Q.push(a[i]);
	}
	
	int sum = 0;
	while(Q.size() > 1) {
		int tmp1 = Q.top();
		Q.pop();
		int tmp2 = Q.top();
		Q.pop();
		sum += tmp1 + tmp2;
		Q.push(tmp1 + tmp2);
	}
	cout << sum << endl;
	return 0;
}