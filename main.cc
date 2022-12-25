#include <iostream>
#include <vector>
#include <string>
#include "classes.h"
#include <fstream>

using namespace std;

int main(){

    PostOffice p;
    Home h;
    char input = 1;
    string s;
    Address a;
    int d;
    int k;
    bool eq;
    Letter l;

    Home home1;
    Address address1;

    ofstream outF;

    outF.open("output.txt");

    if(!outF.fail()){

        while(input != '4'){

            cout << "Menu... " << endl;
            cout << "1... Create a new neighborhood" << endl << "2... Enter the information for a Home" <<
            endl << "3... Add a letter to a home" << endl << "4... Output all the Post Office data into a file and quit" << endl;

            cin >> input;

            switch (input){
                case '1':
                    cout << "Enter a name to name your new neighborhood... " << endl;
                    while(cin.peek() == '\n'){
                        cin.ignore();
                    }
                    getline(cin, s);
                    p.setNeighborhood(s);
                    cout << "Your neighborhood name is... ";
                    p.getNeighborhood(p.getCount()-1).printNeighborhoodName();
                    cout << endl;

                    break;

                case '2':

                    cout << "Enter the information for a NEW HOME... " << endl;
                    cout << "Enter the name: " << endl;
                    while(cin.peek() == '\n'){
                        cin.ignore();
                    }

                    getline(cin, a.name);
                    cout << "Enter the house number" << endl;
                    getline(cin, a.houseNumber);
                    cout << "Enter the street name" << endl;
                    getline(cin, a.streetName);
                    cout << "Enter the city" << endl;
                    getline(cin, a.city);
                    cout << "Enter the state" << endl;
                    getline(cin, a.state);
                    cout << "Enter the zip code (ENTER ONLY 5 INT DIGITS)" << endl;
                    getline(cin, a.zipCode);
                    h.setHomeAddress(a);

                    cout << "Which neighborhood would you like the home to be in? Choose ONLY the number." << endl;
                    p.printNeighborhoods();
                    cin >> d;
                
                    if(p.getNeighborhood(d).getHomeAmount() > 0){
                        for(unsigned int i = 0; i < p.getNeighborhood(d).getHomeAmount(); i++){
                            if(p.getNeighborhood(d).getNeighborhoodHome(i) == h){
                                eq = true;
                            }
                            else{
                                eq = false;
                            }
                        }
                    }
                    else{
                        eq = false;
                    }

                    if(eq == false){
                        p.getNeighborhood(d).setNeighborhoodHome(h);
                    }
                    else{
                        cout << "Sorry, home already exists in this neighborhood!" << endl;
                    }

                    break;


                case '3':
                    cout << "What neighborhood would you like to add your letter to? Choose ONLY the number." << endl;
                    p.printNeighborhoods();
                    cin >> d;

                    cout << "What home would you like to add your letter to? Choose ONLY the number." << endl;
                    p.getNeighborhood(d).printNeighborhoodHomeAddresses();
                    cin >> k;

                    cout << "Enter the name for the FROM portion of the letter... " << endl;
                    while(cin.peek() == '\n'){
                        cin.ignore();
                    }
                    getline(cin, l.from.name);
                    cout << "Enter the house number for the FROM portion of the letter... " << endl;
                    getline(cin, l.from.houseNumber);
                    cout << "Enter the street name for the FROM portion of the letter... " << endl;
                    getline(cin, l.from.streetName);
                    cout << "Enter the city for the FROM portion of the letter... " << endl;
                    getline(cin, l.from.city);
                    cout << "Enter the state for the FROm portion of the letter... " << endl;
                    getline(cin, l.from.state);
                    cout << "Enter the zip code for the FROM portion of the letter (ENTER ONLY 5 INT DIGITS)... " << endl;
                    getline(cin, l.from.zipCode);

                    l.to = p.getNeighborhood(d).getNeighborhoodHome(k).getHomeAddress();

                    p.getNeighborhood(d).getNeighborhoodHome(k).addLetter(l);

                    cout << "Your letter has been set!" << endl;

                    //p.getNeighborhood(d).getNeighborhoodHome(k).printLetters();

                    break;

                case '4':
                    p.printPostOffice(outF);
                    break;

                default:
                    cout << "Invalid input, please enter 1, 2, 3, or 4." << endl;
                    break;
            }
        }
    }

    return 0;

}