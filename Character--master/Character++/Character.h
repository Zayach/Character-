#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

class Character
{
    public:
        Character();

        string classGet() {return charClass;};
        void classSet(string x) {charClass = x;};

        string raceGet() {return race;};
        void raceSet(string x) {race = x;};

        string aliGet() {return alignment;};
        void aliSet(string x) {alignment = x;};

        string backGet() {return background;};
        void backSet(string x) {background = x;};

        string genderGet() {return gender;};
        void genderSet(string x) {gender = x;};

        int statsGet(int x) {return stats[x];};
        void statsSet(int x, int y) {stats[x] = y;};

        string nameGet() {return name;};
        void nameSet(string x) {name = x;};

    private:
        string charClass = "null";
        string race = "null";
        string alignment = "null";
        string background = "null";
        string gender = "null";
        int stats[6] = {0,0,0,0,0,0};
        string name = "null";
};

#endif // CHARACTER_H
