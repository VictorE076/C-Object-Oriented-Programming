// 2.What are constructors and class methods? How to use them?
// 3.What is encapsulation in programming?
// 4.What is inheritance in programming?

#include <iostream>
#include <list>
using namespace std;
class YoutubeChannel
{
private: // These properties being "private" = encapsulation;
    string name;
    string OwnerName;
    unsigned long long SubscribersCount;
    list<string> PublishedVideoTitles;

public:
    //Constructorul are acelasi nume precum clasa sa si nu returneaza nicio valoare;
    YoutubeChannel(string name_p, string OwnerName_p, unsigned long long SubscribersCount_p = 0)
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
    void Publish_Video(const string Title)
    {
        PublishedVideoTitles.push_back(Title);
    }
    void Subscribe()
    {
        SubscribersCount++;
    }
    void Unsubscribe()
    {
        if (SubscribersCount > 0)
        {
            SubscribersCount--;
        }
        else
        {
            cout << "<<" << name << ">> channel has NO subscribers!" << "\n\n";
        }
    }
    // string name;
    const string get_name()
    {
        return name;
    }
    void set_name(const string name_param)
    {
        name = name_param;
    }
};

int main()
{
    YoutubeChannel yt_1("CodeBeauty", "Maria");

    yt_1.Publish_Video("C++ for beginners");
    yt_1.Publish_Video("HTML for begginners");
    yt_1.Publish_Video("C++ OOP");


    YoutubeChannel yt_2("MrBeast", "Jimmy", 114000000);

    yt_2.Publish_Video("I bought a private island");
    yt_2.Publish_Video("24h burried alive");
    yt_2.Publish_Video("I didn't eat for 10 days straight");
    yt_2.Publish_Video("I survived 24h in Antarctica");


    yt_1.get_info();
    yt_2.get_info();

    // !! 3.Encapsulation:
    // yt_1.name = "Gigel" - nu putem accesa aceasta proprietate;

    yt_1.Unsubscribe();
    yt_2.Subscribe();

    yt_1.get_info();
    yt_2.get_info();

    for(int i = 0; i < 5;i++)
    {
        yt_2.Subscribe(); // yt_2 are +5 subs.;
    }
    yt_2.Unsubscribe();
    yt_2.Unsubscribe();
    // yt_2 are -2 subs.;

    yt_1.get_info();
    yt_2.get_info();

    string current_name = yt_2.get_name();
    cout << current_name << endl; // afiseaza yt_2.name;

    current_name = yt_1.get_name();
    cout << current_name << endl; // afiseaza yt_1.name;

    yt_2.set_name("Dude perfect"); // yt_2.name = "Dude perfect";
    current_name = yt_2.get_name();
    cout << current_name << endl; // afiseaza yt_2.name;

    return 0;
}