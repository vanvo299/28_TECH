/*
[STACK]. Bài 17. Next Greater Element (NGE)

ĐỀ: Cho mảng A[] gồm N phần tử, nhiệm vụ của bạn là tìm phần tử đầu tiên bên phải lớn 
hơn của mọi phần tử A[i] trong mảng, nếu không có phần tử bên phải lớn hơn thì in ra -1

*/
#include <bits/stdc++.h>
using namespace std;

void nextGreaterElement(int a[], int n, int res[])
{
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.push(i);
        }
        while(!st.empty() && a[i] > a[st.top()]) {
            res[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    } 
    while(!st.empty()) {
        res[st.top()] = -1; 
        st.pop();
    }
}
int main() 
{
    int n; cin >> n;
    int a[n], res[n];
    for (int &x : a) {
        cin >> x;
    }
    nextGreaterElement(a, n, res);
    for (int x : res) cout << x << " ";
    return 0;
}