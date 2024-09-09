/*
[Sắp xếp - Đèn lồng]. Bài 30. Đèn lồng.

Đề: Vanya đi bộ vào ban đêm dọc theo một con đường thẳng dài có độ dài l, được thắp sáng bởi n chiếc đèn lồng.
Xét hệ trục tọa độ với điểm đầu của đường phố tương ứng với điểm 0 và điểm cuối của nó tương ứng với điểm
l. Khi đó đèn lồng thứ l ở điểm ai. Đèn lồng chiếu sáng tất cả các điểm trên đường phố cách nó nhiều nhất là d,
trong đó d là một số dương, chung cho tất cả các đèn lồng. Vanya tự hỏi bán kính ánh sáng tối thiểu d mà những
chiếc đèn lồng phải có để thắp sáng cả con phố ?
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l; 
    cin >> n >> l;
    int lanterns[n];
    for (int &x : lanterns) cin >> x;

    sort(lanterns, lanterns + n);
    double max_distance = max(lanterns[0], l - lanterns[n - 1]); // so sanh khoang cach cua hai long den ben ngoai
    // khoang cach cua long den thu nhat voi dau duong, long den cuoi cung voi cuoi duong

    for (int i = 0; i < n; i++) {
        max_distance = max(max_distance, (lanterns[i] - lanterns[i - 1]) / 2.0);
    }
    cout << max_distance << endl;
    return 0;
}