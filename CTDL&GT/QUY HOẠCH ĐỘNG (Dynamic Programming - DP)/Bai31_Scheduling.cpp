/*
[DP]. Bài 31. Scheduling

Đề: Có n dự án bạn có thể tham dự. Đối với mỗi dự án, bạn biết ngày bắt đầu và ngày kết thúc
của dự án và số tiền bạn sẽ nhận được khi hoàn thành nó. Bạn chỉ có thể tham dự một sự 
án trong một ngày. Số tiền tối đa bạn có thể kiếm được là bao nhiêu ?

- Input: Dòng đầu tiên chứa số nguyên n: số lượng dự án. Sau đó, có n dòng. Mỗi dòng như vậy có 
ba số nguyên ai, bi, pi: ngày bắt đầu, kết thúc, tiền thưởng.

*/
#include <bits/stdc++.h>
using namespace std;


struct Job {
    int start, end; 
    long long profit;
};

bool cmp(Job a, Job b)
{
    return a.end < b.end;
}

// Tìm vị trí lớn nhất mà nhỏ hơn or bang x
int firstPos(Job a[], int i, int x)
{  
    int l = 1, r = i - 1, res = -1;
    while(l < r) {
        int mid = (l + r) / 2;
        if (a[mid].end <= x) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

Job a[20001];
long long F[200001];

// QHD đệ quy, xây từ lớn về bé

// long long tinh(int n)
// {
//     if (n == 0) return 0;
//     if (F[n] != 0) return F[n];
//     F[n] = 0;
    
//     int t = firstPos(a, n, a[n].start - 1);
//     if (t == -1){
//         F[n] = max(a[n].profit + 0, tinh(n - 1));
//     }
//     else {
//         F[n] = max(a[n].profit + tinh(t), tinh(n - 1));
//     }
//     return F[n];
// }
int main()
{
    int n;
    cin >> n;
    

    for (int i = 1; i <= n; i++) {
        cin >> a[i].start >> a[i].end >> a[i].profit;
    }
    sort(a + 1, a + n + 1, cmp);

    // Quy Hoạch Động, xây từ bé đến lớn

    for (int i = 1; i <= n; i++) {
        int t = firstPos(a, i, a[i].start - 1);
        if (t == -1) {
            F[i] = max(a[i].profit + 0, F[i - 1]);
        }
        else {
            F[i] = max(a[i].profit + F[t], F[i - 1]);
        }
    }
    cout << F[n];

    // cout << tinh(n);
    return 0;
}