/*
[Quay lui - nhánh cận]. Bài 2. Rat in Maze 2;
*/

#include <iostream>
#include <string>
using namespace std;

int n, a[100][100], check = 0;
string S = "";

// thử đi vào ô i, j
void Try(int i, int j)
{
    if (i == n && j == n) {
        check = 1;
        cout << S << endl;
    }

    if (i + 1 <= n && a[i + 1][j] == 1) {
        S += "D";
        a[i + 1][j] = 0;
        Try(i + 1, j);
        S.pop_back();
        a[i + 1][j] = 1;
    }

    if (j + 1 <= n && a[i][j + 1] == 1) {
        S += "R";
        a[i][j + 1] = 0;
        Try(i, j + 1);
        S.pop_back();
        a[i][j + 1] = 1;
    }
    if (i - 1 <= n && a[i - 1][j] == 1) {
        S += "U";
        a[i - 1][j] = 0;
        Try(i - 1, j);
        S.pop_back();
        a[i - 1][j] = 1;
    }
    if (j - 1 <= n && a[i][j - 1] == 1) {
        S += "L";
        a[i][j - 1] = 0;
        Try(i, j - 1);
        S.pop_back();
        a[i][j - 1] = 1;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    Try(1, 1);
    if (check == 0) cout << "-1" << endl;
    cout << endl;
    return 0;
}