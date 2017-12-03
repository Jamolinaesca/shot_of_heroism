#ifndef SHOTOFHEROISM_H_INCLUDED
#define SHOTOFHEROISM_H_INCLUDED
#include <iostream>
#include <fstream>
 
using namespace std;
 
class scene1
{
public:
    //avatar text file
    string avatarchoice = "";
 
    //avatar data from file for choice
    string weapon = "";
    string monster = "";
    string avatar = "";
    string location = "";
    string card = "";
 
public:
    //choice for attack
    int choice;
 
    //avatar fight scene data
    double stats[3];
    double mstats[3];
    double hp;
 
    //monster fight scene data
    double mhp;
    double mdamage;
    double damage;
 
public:
    //constructor
    scene1();
 
    //battle
    int battle();
 
    //method to search data from avatar files
    void file_search();
 
    //avatar moves
    void strong_attack();
    void light_attack();
    void defense();
 
    //monster moves
    void mstrong_attack();
    void mlight_attack();
    void mdefense();
 
    //inflicted damage
    double monster_damage();
    double avatar_damage();
};
 
class Task
{
public:
    //points to level up
    int light_points;
 
    //puzzle game
    string random_words[3];
    string correct_words[3];
    string choice;
 
public:
    //constructor
    Task();
 
    //method for word game in program
    void word_game();
 
    //method to see if avatar can level up
    bool level_up();
};
#endif // SHOTOFHEROISM_H_INCLUDED
