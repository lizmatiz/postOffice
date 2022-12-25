#include <string>
#include <vector>
#ifndef CLASSES
#define CLASSES

using namespace std;

struct Address{
    string name;
    string houseNumber;
    string streetName;
    string city;
    string state;
    string zipCode;
};

struct Letter{
    Address to;
    Address from;
    string barcode;
};

class Home{
    public:
        Home();
        void setHomeAddress(Address a);
        friend bool operator == (Home home1, Home home2);
        Address getHomeAddress();
        void printHomeAddress();
        string getHomeAddressName();
        void addLetter(Letter l);
        void printLetters();
        void printHomeLetters(ofstream &outF);


    private:
        Address homeAddress;
        vector <Letter> homeLetters;



};

class Neighborhood{

    public:
        Neighborhood(){name = "";}
        void setName(string s);
        void printNeighborhoodName();
        int getHomeAmount();
        Home &getNeighborhoodHome(int i);
        void setNeighborhoodHome(Home h);
        void printNeighborhoodHomeAddresses();
        void printNeighborhoodInfo(ofstream &outF);

    private:
        string name;
        vector <Home> neighborhoodHomes;
};

class PostOffice{
    public:
        static const int SIZE = 5;
        PostOffice(){count = 0;}
        void setNeighborhood(string s);
        int getCount(){return count;}
        Neighborhood &getNeighborhood(int i){return neighborhoods[i];}
        void printNeighborhoods();
        void printPostOffice(ofstream &outF);


    private:
        Neighborhood neighborhoods[SIZE];
        int count;

};

string create_barcode(string zipCode);

#endif