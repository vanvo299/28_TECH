#include <iostream>
#include <list>
using namespace std;

class YoutubeChannel {
    public:
    string nameChannel;
    string Owner;
    int SubcribersCount;
    list<string> PublishedVideoTitles;

    // Dung construction de de dang trong viec tao Object, ngan gon code va khong vi pham nguyen tac lap lai code
    YoutubeChannel(string name, string nameOwner, int subcriber) {
        nameChannel = name;
        Owner = nameOwner;
        SubcribersCount = subcriber;
    }

    void getInfo() {
        cout << "Name channel: " << nameChannel << endl;
        cout << "Name owner: " << Owner << endl;
        cout << "Subcribers: " << SubcribersCount << endl;
        cout << "Video titles: " << endl;
        for (string video : PublishedVideoTitles) {
            cout << video << endl;
        }
    }
};
int main()
{
    YoutubeChannel YtChannel1("Mixigaming", "Phung Thanh Do", 10000);
    YtChannel1.PublishedVideoTitles.push_back("FC Online");
    YtChannel1.PublishedVideoTitles.push_back("Mixi vlog: Hue va Da Nang");
    YtChannel1.PublishedVideoTitles.push_back("Ao lang Pubg");

    YoutubeChannel YtChannel2("Nhism", "Tran Thai Linh", 7000);
    YtChannel2.PublishedVideoTitles.push_back("Reaction anh Do Mixi");
    YtChannel2.PublishedVideoTitles.push_back("PUBG cung Rambo");

    YtChannel1.getInfo();
    cout << endl;
    YtChannel2.getInfo();

    return 0;
}