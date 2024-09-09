// Tính đóng gói (Encapsulation)

#include <iostream>
#include <list>
using namespace std;

class YoutubeChannel {
private:
    string nameChannel;
    string Owner;
    int SubcribersCount;
    list<string> PublishedVideoTitles;
public:
    // Dung construction de de dang trong viec tao Object, ngan gon code va khong vi pham nguyen tac lap lai code
    YoutubeChannel(string name, string nameOwner) {
        nameChannel = name;
        Owner = nameOwner;
        SubcribersCount = 0;
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
    
    void Subcribers() {
        SubcribersCount++;
    }
    void Unsubcribers() {
        if (SubcribersCount >0) SubcribersCount--;
    }
    void PublishedVideo(string title) {
        PublishedVideoTitles.push_back(title);
    }
};
int main()
{
    YoutubeChannel YtChannel1("Mixigaming", "Phung Thanh Do");
    YtChannel1.PublishedVideo("Ao lang PUBG");
    YtChannel1.PublishedVideo("Mixi vlog");
    YtChannel1.Subcribers();
    YtChannel1.Subcribers();
    YtChannel1.Subcribers();
    YtChannel1.Unsubcribers();
    YoutubeChannel YtChannel2("Nhism", "Tran Thai Linh");
    YtChannel2.PublishedVideo("Mo the FC Online");
    YtChannel2.PublishedVideo("Reaction anh Do Mixi");
    YtChannel2.Subcribers();
    YtChannel2.Subcribers();
    YtChannel2.Subcribers();

    
    YtChannel1.getInfo();
    cout << endl;
    YtChannel2.getInfo();

    return 0;
}