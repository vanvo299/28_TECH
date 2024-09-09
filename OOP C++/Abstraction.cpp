#include <iostream>
using namespace std;

class SmartPhone {
public:
    virtual void TakeASelfie() = 0;
    virtual void MakeACall() = 0;
};

class SamSung : public SmartPhone {
public:
    void TakeASelfie() {
        cout << "Samsung selfie\n";
    }
    void MakeACall() {
        cout << "Samsung calling\n";
    }
};

class iPhone : public SmartPhone {
public:
    void TakeASelfie() {
        cout << "iPhone selfie\n";
    }
    void MakeACall() {
        cout << "iPhone calling\n";
    }
};
int main()
{
    SmartPhone *s1 = new SamSung;
    s1->TakeASelfie();
    s1->MakeACall();

    SmartPhone *s2 = new iPhone;
    s2->TakeASelfie();
    s2->MakeACall();
    return 0;
}