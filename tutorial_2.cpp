// What are constructors and class methods? How to use them?
#include <iostream>
#include <list>
using namespace std;
class YoutubeChannel
{
private:
    string name;
    string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles;

public:
    //Constructorul are acelasi nume precum clasa sa si nu returneaza nicio valoare;
    YoutubeChannel(string name_p, string OwnerName_p, unsigned int SubscribersCount_p = 0)
    {
        name = name_p;
        OwnerName = OwnerName_p;
        SubscribersCount = SubscribersCount_p;
    }

    //Below there are some class methods;
    void get_info()
    {
        cout << "Name: " << name << endl;
        cout << "OwnerName: " << OwnerName << endl;
        cout << "Subs.count: " << SubscribersCount << endl;
        cout << endl << "Videos for " << name << " youtube channel:\n";
        for(string el:PublishedVideoTitles)
        {
            cout << el << endl;
        }
        cout << "\n\n";
    }
    void fill_VideoTitles(const string Title)
    {
        PublishedVideoTitles.push_back(Title);
    }
};

int main()
{
    YoutubeChannel yt_1("CodeBeauty", "Maria");


    yt_1.fill_VideoTitles("C++ for beginners");
    yt_1.fill_VideoTitles("HTML for begginners");
    yt_1.fill_VideoTitles("C++ OOP");

    YoutubeChannel yt_2("MrBeast", "Jimmy", 114000000);


    yt_2.fill_VideoTitles("I bought a private island");
    yt_2.fill_VideoTitles("24h burried alive");
    yt_2.fill_VideoTitles("I didn't eat for 10 days straight");


    yt_2.get_info();
    yt_1.get_info();


    return 0;
}