#include <iostream>
#include <fstream>
#include "shotofHeroism.h"
 
using namespace std;
 
int main()
{
    //access classes
    scene1 avatars, battles;
    Task task;
 
    //action from avatar
    char weapon_activation;
 
    //story lines for chosen avatar
    cout << "Chose your Story by typing avatar and #: "<<endl<<endl;
    cout << "1) Transform the world for the better and become immortal"<<endl;
    cout << "2) Create a new civilization and be their guardian for knowledge"<<endl;
    cout << "3) Speak for the people and represent earth in a global alliance"<<endl;
    cout << "4) Heal the injured and help others become their greatest version"<<endl;
    cout << "5) Rule a whole nation and lead them towards peace and prosperity"<<endl;
    cout << "6) Play and perform in the capital of the world with great joy and emotion"<<endl;
    cout << "7) Hunt the wild beast and save the world from total destruction"<<endl<<endl;
    cin >> avatars.avatarchoice;
 
    //method to read file from avatar
    avatars.file_search();
 
    //start prompt when chosen avatar
    cout << "Welcome " << avatars.avatar <<endl;
    cout << "Here is your " << avatars.weapon <<endl<<endl;
 
    //choose adventure or read card from character
    cout << "Press (z) to activate your weapon and start your adventure!"<<endl;
    cin >> weapon_activation;
 
        if (weapon_activation == 'z')
        {
            //saved path for desired destiny
            char destiny_activation;
 
            //prompt to choose destiny
            cout << "Choose your destiny: \n";
            cout << "a) Battle your Demon"<< endl;
            cout << "b) Level up in "<< avatars.location << endl;
            cin >> destiny_activation;
 
            //statements to start battle or game, depending on choice
            if (destiny_activation == 'a'){
            cout << "You will battle: " << avatars.monster <<endl;
            battles.battle();
            }
            else if (destiny_activation == 'b')
            {
                ofstream infile;
                infile.open("Avatar Card.txt", ios::out);
                infile << avatars.card;
 
                cout << "Read character card after leveling up"<<endl;
                task.word_game();
            }
        }
}
