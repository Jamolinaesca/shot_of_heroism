#include <iostream>
#include <cstdlib>
#include <ctime>
#include "shotofHeroism.h"
using namespace std;
 
//scene 1 constructor to access data members
scene1::scene1(){
    avatar = "";
    weapon = "";
    monster = "";
    card = "";
    location = "";
 
    srand(unsigned(time(0)));
 
    stats[0] = 0;
    stats[1] = 0;
    stats[2] = 0;
 
    mstats[0] = 0;
    mstats[1] = 0;
    mstats[2] = 0;
 
    mhp = rand()%20+80;
    hp = rand()%20+80;
    choice;
}
 
//read file to assign items for avatar
void scene1::file_search()
{
    string avatarfile = avatarchoice + ".txt";
    ifstream infile;
    infile.open(avatarfile.c_str(), ios::in);
 
    if (infile.fail())
    {
        cout << "File open error" <<endl;
    }
 
    int x = 0;
    if (infile.is_open())
    {
        string line;
 
        while (getline(infile, line))
        {
            if (x == 0)
                {
                    avatar = line;
                }
            else if (x == 1)
                {
                    weapon = line;
                }
            else if(x == 2)
                {
                    monster = line;
                }
            else if (x == 3)
                {
                    location = line;
                }
            else if (x == 4)
                {
                    card = line;
                }
            x++;
        }
    }
    infile.close();
}
 
//calculate stats for avatar in battle
void scene1::strong_attack()
{
    stats[0] = rand()%45+35;
    stats[1] = rand()%5+10;
    stats[2] = rand()%15+25;
}
 
void scene1::light_attack()
{
    stats[0] = rand()%25+15;
    stats[1] = rand()%10+20;
    stats[2] = rand()%5+10;
}
 
void scene1::defense()
{
    stats[0] = rand()%1+5;
    stats[1] = rand()%35+25;
    stats[2] = rand()%1+5;
}
//calculate stats for avatar in battle
 
//calculate stats for monster in battle
void scene1::mstrong_attack()
{
    mstats[0] = rand()%30+20;
    mstats[1] = rand()%1+5;
    mstats[2] = rand()%15+25;
}
 
void scene1::mlight_attack()
{
    mstats[0] = rand()%20+15;
    mstats[1] = rand()%5+15;
    mstats[2] = rand()%5+10;
}
 
void scene1::mdefense()
{
    mstats[0] = rand()%1+5;
    mstats[1] = rand()%25+15;
    mstats[2] = rand()%1+5;
}
//calculate stats for monster in battle
 
//calculate monster damage
double scene1::monster_damage()
{
    double damage1 = stats[0]/mstats[2];
    double damage2 = mstats[1]/stats[0];
 
    double total_damage = damage1 + damage2;
    return total_damage;
}
 
//calculate avatar damage for battle
double scene1::avatar_damage()
{
    double damage1 = mstats[0]/stats[2];
    double damage2 = stats[1]/mstats[0];
 
    double total_damage = damage1 + damage2;
    return total_damage;
}
//calculate avatar damage for battle
 
//Battle Scene
int scene1::battle()
{
    cout << "The fight has begun!" <<endl;
    while (hp > 0 || mhp > 0){
        cout << "What is your first move?\n 1)Strong Attack \n 2)Light Attack \n 3)Shield \n "<<endl;
        do{cin >> choice;}
 
        while(choice > 3 || choice < 1);
        switch (choice){
        case 1:
            strong_attack();
            break;
        case 2:
            light_attack();
            break;
        case 3:
            defense();
            break;
            }
 
        choice = rand()%3;
 
        switch (choice){
        case 1:
            mstrong_attack();
            break;
        case 2:
            mlight_attack();
            break;
        case 3:
            mdefense();
            break;
            }
 
        mdamage = monster_damage();
 
        if (mdamage < 0){
            mdamage = 0;
        }
 
        mhp = mhp - mdamage;
        cout << "Your power inflicted " << mdamage << " damage \n";
        cin.get();
 
        if (mhp < 1){
            cout << "You have killed your opponent \n!";
            cin.get();
            return 0;
        }
 
        cout << "Your opponent now has " << mhp << " HP left "<<endl;
 
        damage = avatar_damage();
 
        if (damage < 0){
            damage = 0;
        }
 
        hp = hp - damage;
        cout << "Your opponent hit you with " << damage <<" damage" <<endl;
 
        if (hp < 1){
            cout << "You died";
            cin.get();
            return 0;
        }
        else {
 
        while (hp > 0 || mhp > 0){
            cout << "What is your next move?\n 1)Fierce Attack \n 2)Light Attack \n 3)Shield \n "<<endl;
            do{cin >> choice;}
 
            while(choice > 3 || choice < 1);
            switch (choice){
            case 1:
                strong_attack();
                break;
            case 2:
                light_attack();
                break;
            case 3:
                defense();
                break;
                }
 
            choice = rand()%3;
 
             switch (choice){
            case 1:
                mstrong_attack();
                break;
            case 2:
                mlight_attack();
                break;
            case 3:
                mdefense();
                break;
                }
 
            mdamage = monster_damage();
 
            if (mdamage < 0){
                mdamage = 0;
            }
 
            mhp = mhp - mdamage;
            cout << "Your power inflicted " << mdamage << " damage \n";
            cin.get();
 
            if (mhp < 1){
                cout << "You have killed your opponent \n!";
                cin.get();
                return 0;
            }
 
            cout << "Your opponent now has " << mhp << " HP left "<<endl;
 
            damage = avatar_damage();
 
            if (damage < 0){
                damage = 0;
            }
 
            hp = hp - damage;
            cout << "Your opponent hit you with " << damage <<" damage" <<endl;
 
            if (hp < 1){
                cout << "You died";
                cin.get();
                return 0;
            }
        }
    }
}
}
//battle scene
 
//////////////////////////////////
 
//constructor for task class
Task::Task(){
    light_points = 0;
 
    random_words[0] = {"drmea"};
    random_words[1] = {"cigam"};
    random_words[2] = {"nawd"};
 
    correct_words[0] = {"dream"};
    correct_words[1] = {"magic"};
    correct_words[2] = {"wand"};
 
    choice;
}
 
//word game scene
void Task::word_game()
{
    bool x = false;
    while(!x)
    {
        light_points = 0;
        cout << "Guess the correct word"<<endl;
        for(int index = 0; index < 3; index++)
        {
            random_words[index];
 
            cout << random_words[index] <<endl<<endl;
            cin >> choice;
 
            if (choice == correct_words[index]){
                light_points++;
                cout << "Congratulations you have guessed the correct word!"<<endl<<endl;
            }
            else if (choice != correct_words[index]){
                cout << "Wrong!"<<endl<<endl;
            }
        }
        x = level_up();
        cout << "LEVEL UP!";
    }
 
}
 
//method to see if avatar is ready to level up
bool Task::level_up()
{
    if (light_points = 3)
        return true;
    else
        return false;
}
