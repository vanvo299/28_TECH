/*
[STACK]. Bài 19. Largest Rectangle Area in a Histogram

ĐỀ: Cho một biểu đồ gồm các cột với chiều cao H[i], nhiệm vụ của bạn là tìm hình chữ nhật có
diện tích lớn nhất che phủ bởi các cột trong biểu đồ.

*/
// Tìm phần tử nhỏ hơn đầu tiên bên trái và bên phải của phân tử đang xét đến

#include <bits/stdc++.h>
using namespace std;

// Tìm vị trí của phần tử nhỏ hơn đầu tiên bên trái của mỗi phần tử trong mảng
void smaller_left(int a[], int n, int L[])
{
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while(!st.empty() && a[i] < a[st.top()]) {
            L[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        L[st.top()] = -1;
        st.pop();
    }
}

// Tìm vị trí của phần tử nhỏ hơn đầu tiên bên phải của mỗi phần tử trong mảng
void smaller_right(int a[], int n, int R[]) 
{
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while(!st.empty() && a[i] < a[st.top()]) {
            R[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        R[st.top()] = n;
        st.pop();
    }
}

int main()
{
    long long res = 0;
    int n; cin >> n;
    int a[n], L[n], R[n];
    for (int &x : a) cin >> x;

    smaller_left(a, n, L);
    smaller_right(a, n, R);

    for (int i = 0; i < n; i++) {
        int w = R[i] - L[i] - 1;
        long long dienTich = w * a[i];
        res = max(res, dienTich);
    }
    cout << "Dien tich lon nhat cua do thi la: " <<  res << endl;
    return 0;
}