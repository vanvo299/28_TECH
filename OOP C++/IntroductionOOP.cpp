#include <iostream>
#include <list>
using namespace std;

class classOfSchool {
    public: 
    string nameClass;
    string nameOwner;
    int studentCount;
    list<string> nameStudent;
};

int main()
{
    classOfSchool classSchool;
    classSchool.nameClass = "23T_DT1";
    classSchool.nameOwner = "Bui Thi Thanh Thanh";
    classSchool.studentCount = 53;
    classSchool.nameStudent = {"Luong Van Vo", "Phan Van Truong", "Dinh Minh Tue"};

    cout << "Name class: " << classSchool.nameClass << endl;
    cout << "Name owner class: " << classSchool.nameOwner << endl;
    cout << "Student count: " << classSchool.studentCount << endl;
    cout << "Name of student in the class: " << endl;
    for (string student : classSchool.nameStudent) {
        cout << student << endl;
    }
    return 0;
}