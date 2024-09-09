// Tính kế thừa (Inheritance)

#include <iostream>
#include <list>
using namespace std;

class YoutubeChannel {
private:
    string nameChannel;
    int SubcribersCount;
    list<string> PublishedVideoTitles;
protected: // tác dụng: có thể truy cập Owner trong class dẫn xuất
    string Owner;
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

// Tạo một class dẫn xuất của class cơ sở là YoutubeChannel
class GamingYouTubeChannel : public YoutubeChannel {
public:     
    GamingYouTubeChannel(string name, string ownerName) : YoutubeChannel(name, ownerName) {

    }

    void Practice() {
        cout << Owner << " is training PUBG, Valorant, CS2, League of Legend\n";
    }
};
int main()
{
    GamingYouTubeChannel GamingChannel("Mixigaming", "Phung Thanh Do");
    GamingChannel.PublishedVideo("Ao lang FC Online");
    GamingChannel.PublishedVideo("Ao lang PUBG");
    for (int i = 0; i < 100; i++) {
        GamingChannel.Subcribers();
    }
    GamingChannel.getInfo();
    GamingChannel.Practice();

    cout << endl;
    GamingYouTubeChannel GamingChannel2("Nhism", "Tran Thai Linh");
    GamingChannel2.PublishedVideo("Mo the FC Online");
    GamingChannel2.PublishedVideo("Co Ty Phu with friends");
    for (int i = 0; i < 100; i++) {
        GamingChannel2.Subcribers();
    }
    GamingChannel2.getInfo();
    GamingChannel2.Practice();
    return 0;
}