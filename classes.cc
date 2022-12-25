#include "classes.h"
#include <iostream>
#include <fstream>

using namespace std;

//HOME
Home::Home(){
    homeAddress.name = "default";
    homeAddress.houseNumber = "default";
    homeAddress.streetName = "default";
    homeAddress.city = "default";
    homeAddress.state = "default";
    homeAddress.zipCode = "default";
}

void Home::setHomeAddress(Address a){
    homeAddress = a;
}

Address Home::getHomeAddress(){
    return homeAddress;
}

void Home::printHomeAddress(){
    cout << homeAddress.name << endl;
    cout << homeAddress.houseNumber << " " << homeAddress.streetName << endl;
    cout << homeAddress.city << ", " << homeAddress.state << " " << homeAddress.zipCode << endl;
}

void Home::addLetter(Letter l){
    homeLetters.push_back(l);
}

void Home::printLetters(){
    for(unsigned int i = 0; i < homeLetters.size(); i++){
        cout << homeLetters[i].to.name << endl;
    }
}

void Home::printHomeLetters(ofstream &outF){
    for(unsigned int i = 0; i < homeLetters.size(); i++){
        outF << "Letter " << i+1 << "... " << endl << endl;
        outF << "To: " << endl;
        outF << homeLetters[i].to.name << endl;
        outF << homeLetters[i].to.houseNumber << " " << homeLetters[i].to.streetName << endl;
        outF << homeLetters[i].to.city << ", " << homeLetters[i].to.state << " " << homeLetters[i].to.zipCode << endl << endl;
        
        outF << "From: " << endl;
        outF << homeLetters[i].from.name << endl;
        outF << homeLetters[i].from.houseNumber << " " << homeLetters[i].from.streetName << endl;
        outF << homeLetters[i].from.city << ", " << homeLetters[i].from.state << " " << homeLetters[i].from.zipCode << endl << endl;

        outF << "Barcode: " << endl;
        outF << create_barcode(homeLetters[i].to.zipCode) << endl << endl;
        

    }

}

string create_barcode(string zipCode){
    int sum; // sum of the digits
    char check; // check digit
    string barcode = "|"; // the string the barcode ends up at
    char digit; // a digit in the zip

    string a; // a - fifth_digit help separate the zip code into digits
    string b;
    string c;
    string d;
    string e;
    int first_dig;
    int second_dig;
    int third_dig;
    int fourth_dig;
    int fifth_dig;
    
    // assigns each digit to its own string variable
    a = zipCode[0];
    b = zipCode[1];
    c = zipCode[2];
    d = zipCode[3];
    e = zipCode[4];

    // converts each string to an int
    first_dig = stoi(a);
    second_dig = stoi(b);
    third_dig = stoi(c);
    fourth_dig = stoi(d);
    fifth_dig = stoi(e);   

    // adds all the digits together
    sum = first_dig + second_dig + third_dig + fourth_dig + fifth_dig;
    int i = sum % 10;

    // switch statement sets the check variable equal to the check digit
    switch(i){
        case 1:
            check = '9';
            break;
        case 2:
            check = '8';
            break;
        case 3:
            check = '7';
            break;
        case 4:
            check = '6';
            break;
        case 5:
            check = '5';
            break;
        case 6:
            check = '4';
            break;
        case 7:
            check = '3';
            break;
        case 8:
            check = '2';
            break;
        case 9:
            check = '1';
            break;
        default:
            check = '0';
            break;
    }
    
    // adds to the barcode string for each digit in the zip
    for(int i = 0; i < 5; i++){
        digit = zipCode[i];
        switch (digit){
            case '0':
                barcode += "||:::";
                break;
            case '1':
                barcode += ":::||";
                break;
            case '2':
                barcode += "::|:|";
                break;
            case '3':
                barcode += "::||:";
                break;
            case '4':
                barcode += ":|::|";
                break;
            case '5':
                barcode += ":|:|:";
                break;
            case '6':
                barcode += ":||::";
                break;
            case '7':
                barcode += "|:::|";
                break;
            case '8':
                barcode += "|::|:";
                break;
            case '9':
                barcode += "|:|::";
                break;
            default:
                barcode += "*";
                break;
        }
    }

    // adds to the barcode for the check digit
    digit = check;
        switch (digit){
        case '0':
            barcode += "||:::";
            break;
        case '1':
            barcode += ":::||";
            break;
        case '2':
            barcode += "::|:|";
            break;
        case '3':
            barcode += "::||:";
            break;
        case '4':
            barcode += ":|::|";
            break;
        case '5':
            barcode += ":|:|:";
            break;
        case '6':
            barcode += ":||::";
            break;
        case '7':
            barcode += "|:::|";
            break;
        case '8':
            barcode += "|::|:";
            break;
        case '9':
            barcode += "|:|::";
            break;
        default:
            barcode += "*";
            break;

    }

    // adds the end bar to the barcode
    barcode += "|";
    return barcode;

}



//NEIGHBORHOOD

void Neighborhood::setName(string s){
    name = s;
}

void Neighborhood::printNeighborhoodName(){
    cout << name;
}

int Neighborhood::getHomeAmount(){
    return neighborhoodHomes.size();
}

Home &Neighborhood::getNeighborhoodHome(int i){
    return neighborhoodHomes[i];
}

void Neighborhood::setNeighborhoodHome(Home h){
    neighborhoodHomes.push_back(h);
    //cout << "neighborhood home size: " << neighborhoodHomes.size() << '\n';
}

void Neighborhood::printNeighborhoodHomeAddresses(){
    for (int i = 0; i < neighborhoodHomes.size(); i++){
        cout << "Home " << i << "... " << endl;
        getNeighborhoodHome(i).printHomeAddress();
    }
}

void Neighborhood::printNeighborhoodInfo(ofstream &outF){
    for(unsigned int i = 0; i < neighborhoodHomes.size(); i++){
        outF << "Home " << i+1 << "... " << endl << endl;
        neighborhoodHomes[i].printHomeLetters(outF);
    }
}


//POSTOFFICE

void PostOffice::setNeighborhood(string s){
    neighborhoods[count].setName(s);
    count ++;
}

void PostOffice::printNeighborhoods(){
    for (int i = 0; i < count; i++){
        cout << i << "... ";
        neighborhoods[i].printNeighborhoodName();
        cout << endl;
    }
}

void PostOffice::printPostOffice(ofstream &outF){
    outF << "Post Office General Information Report" << endl;
    outF << "-----------------------------------------" << endl;
    for(unsigned int i = 0; i < count; i++){
        outF << "-----------------------------------------" << endl;
        outF << "Neighborhood " << i+1 << endl;
        outF << endl << endl;
        getNeighborhood(i).printNeighborhoodInfo(outF);
        outF << "-----------------------------------------" << endl;
    }
}

// FRIENDS

bool operator == (Home home1, Home home2){
    return (home1.homeAddress.name == home2.homeAddress.name) && (home1.homeAddress.houseNumber == home2.homeAddress.houseNumber) 
    && (home1.homeAddress.streetName == home2.homeAddress.streetName) && (home1.homeAddress.city == home2.homeAddress.city) && (home1.homeAddress.state == home2.homeAddress.state) 
    && (home1.homeAddress.zipCode == home2.homeAddress.zipCode);
}