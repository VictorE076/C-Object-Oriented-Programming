// 2.What are constructors and class methods? How to use them?
// 3.What is encapsulation in programming?
// 4.What is inheritance in programming?
// 5.What is polymorphism in programming?

#include <iostream>
#include <list>
using namespace std;

// Base class;
class YoutubeChannel
{
private: // These properties being "private" = encapsulation;
    string name;
    unsigned long long SubscribersCount;
    list<string> PublishedVideoTitles;

protected:
    string OwnerName;

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

// 4.Inheritance;
// Derived class;
class Cooking_YoutubeChannel: public YoutubeChannel 
{
// !! Toate metodele publice din clasa YoutubeChannel vor fi mostenite in Cooking_YoutubeChannel,
// acestea la randul lor fiind publice;

public:
    // Avem nevoie de constructor si in "derived class", dar putem specifica constructorul din 
    // "base class" daca avem aceeasi regula, cu aceeasi parametrii (tipul si numarul lor) 
    // pt. constructor;
    Cooking_YoutubeChannel(string name_pr, string ownerName_pr, unsigned long long subsCount_pr = 0):
    YoutubeChannel(name_pr, ownerName_pr, subsCount_pr)
    {
    }

    // !! Below are things and methods that are specific for this "derived class" only:
    void Practice()
    {
        // !! "OwnerName" MUST be decleared protected in base class to be accessible in 
        // derived classes;
        cout << OwnerName 
        << " is practicing cooking, learning new recipes, experimenting with spices..." << "\n\n";
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
    cout << "\n\n\n";


    // !! 4.Inheritance:
    
    Cooking_YoutubeChannel c_yt_1("Amy's Kitchen", "Amy");
    Cooking_YoutubeChannel c_yt_2("Kitchen Nightmares", "Gordon Ramsay", 3700000);

    c_yt_1.Publish_Video("Apple pie");
    c_yt_2.Publish_Video("Simple dinner");
    c_yt_2.Publish_Video("Simple breakfast");
    c_yt_1.Publish_Video("Chocolate cake");
    c_yt_2.Publish_Video("Simple lunch");


    c_yt_1.get_info();
    c_yt_2.get_info();

    c_yt_1.Unsubscribe();
    for(int i = 0;i < 10;i++)
    {
        c_yt_2.Subscribe();
    }
    c_yt_1.Unsubscribe();
    c_yt_1.Subscribe();
    c_yt_1.Subscribe();
    c_yt_1.Unsubscribe();
    c_yt_1.Subscribe();

    c_yt_2.Unsubscribe();

    // c_yt_1.name = "Jim"; - is private and inaccessible!

    c_yt_1.get_info();
    c_yt_2.get_info();

    c_yt_1.Practice();
    c_yt_2.Practice();
    // yt_1.Practice(); - object "yt_1" from base "YoutubeChannel" class has no method "Practice";

    // !! Lines below are inaccessible because "OwnerName" is protected and "name" is private
    // in base and derived class;
    /*
    yt_1.OwnerName = "Jimy";
    yt_1.name = "Bun";
    c_yt_1.name = "Bunaa";
    c_yt_2.OwnerName = "Ema";
    */
    

    // !! 5.Polymorphism:
    //

    return 0;
}