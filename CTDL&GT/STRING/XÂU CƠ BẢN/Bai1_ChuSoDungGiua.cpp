/*
[Xâu kí tự cơ bản]. Bài 1. Chữ số đứng giữa

Đề: Cho số nguyên không âm N, hãy xác định chữ số đứng giữa của N, trong trường hợp N không có chữ số đứng
giữa thì in ra "NOT FOUND". Ví dụ N = 12345 thì số đứng giữa là 3, N = 2213 thì không có chữ số đứng giữa.
*/
#include <iostream>
#include <string>
using namespace std;

using ll = long long;

int main()
{
    string N; cin >> N;
    if (N.size() % 2 == 0) {
        cout << "NOT FOUND\n";
    } else {
        cout << N[N.size() / 2];
    }
    return 0;
}