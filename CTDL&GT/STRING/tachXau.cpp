// Tách từ bằng stringstream theo dấu cách

#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    while(ss >> word) {
        cout << word << endl;
    }
    return 0;
}