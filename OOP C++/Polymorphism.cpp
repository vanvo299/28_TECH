// Tính đa hình (Polymorphism)

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
    int QualityContent = 0;
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
    void CheckAnalytics() {
        if (QualityContent < 5) {
            cout << nameChannel << " has bad quality content." << endl;
        } else 
            cout << nameChannel << " has great quality content." << endl;
    }
};

// Tạo một class dẫn xuất của class cơ sở là YoutubeChannel
class GamingYouTubeChannel : public YoutubeChannel {
public:     
    GamingYouTubeChannel(string name, string ownerName) : YoutubeChannel(name, ownerName) {

    }

    void Practice() {
        cout << Owner << " is training PUBG, Valorant, CS2, League of Legend\n";
        QualityContent++;
    }
};

class SingersYouTubeChannel : public YoutubeChannel {
public:
    SingersYouTubeChannel(string name, string ownerName) : YoutubeChannel(name, ownerName) {

    }
    void Practice() {
        cout << Owner << " is taking singing classes, learing new songs, learing how to dance..." << endl;
        QualityContent++;
    }
};
int main()
{
    GamingYouTubeChannel gamingChannel("Mixigaming", "Phung Thanh Do");
    SingersYouTubeChannel singerChannel("Son Tung MTP", "Nguyen Thanh Tung");

    gamingChannel.Practice();
    singerChannel.Practice();
    singerChannel.Practice();
    singerChannel.Practice();
    singerChannel.Practice();
    singerChannel.Practice();
    cout << endl;

    gamingChannel.CheckAnalytics();
    singerChannel.CheckAnalytics();

    // co the dung con tro de goi cac phuong thuc
    YoutubeChannel *yt1 = &gamingChannel;
    YoutubeChannel *yt2 = &singerChannel;
    yt1->CheckAnalytics();
    yt2->CheckAnalytics();

    return 0;
}