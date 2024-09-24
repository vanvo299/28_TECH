/*
[STACK]. Bài 18. Phần tử nhỏ hơn bên phải

ĐỀ: Cho mảng A[] có n phần tử, nhiệm vụ của bạn là đối với mỗi phần tử A[i] trong mảng phải
tìm ra phần tử nhỏ hơn đầu tiên nằm bên phải của phân tử lớn hơn đầu tiên nằm bên phảỉ
của A[i]. Đối với những phần tử không có phần tử lớn hơn bên phải thì in ra -1. Ví dụ
A[] = {1, 5, 3, 3, 4, 1}, 1->5->3, 5->-1->-1, 3->4->1, 3->4->1, 4->-1->-1, 1->-1->-1

*/
#include <bits/stdc++.h>
using namespace std;

// Tìm vị trí của phần tử lớn hơn đầu tiên bên phải của mỗi phần tử trong mảng
void greater_right(int a[], int n, int GR[]) 
{
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while(!st.empty() && a[i] > a[st.top()]) {
            GR[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        GR[st.top()] = -1;
        st.pop();
    }
}

// Tìm vị trí của phần tử nhỏ hơn đầu tiên bên phải của mỗi phần tử trong mảng
void smaller_right(int a[], int n, int SR[]) 
{
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while(!st.empty() && a[i] < a[st.top()]) {
            SR[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        SR[st.top()] = -1;
        st.pop();
    }
}

int main()
{
    int n; cin >> n;
    int a[n], SR[n], GR[n];

    for (int &x : a) cin >> x;

    greater_right(a, n, GR);
    smaller_right(a, n, SR);

    for (int i = 0; i < n; i++) {
        if (GR[i] != -1)
            cout << a[SR[GR[i]]] << ' ';
        else cout << -1 << ' ';
    }
    return 0;
}