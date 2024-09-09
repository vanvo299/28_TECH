// Hàm ảo (Virtual Function)'
#include <iostream>
using namespace std;

class Instrument {
public:
    virtual void MakeSound() = 0;
};

class Guitar : public Instrument {
public: 
    void MakeSound() {
        cout << "Guitar playing...." << endl;
    }
};

class Piano : public Instrument {
public: 
    void MakeSound() {
        cout << "Piano playing..." << endl;
    }
};
int main()
{
    Instrument *i1 = new Guitar;
    // i1->MakeSound();
    Instrument *i2 = new Piano;
    // i2->MakeSound();

    Instrument *instruments[2] = {i1, i2};
    
    for (int i = 0; i < 2; i++) {
        instruments[i]->MakeSound();
    } 
    return 0;
}