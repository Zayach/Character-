#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int diceRoll(int numDice, int sidesDice){
    int diceTotal = 0;
    for(int i = 0; i < numDice; i++){
        diceTotal = (rand()%sidesDice+1) + diceTotal;
    }
    return diceTotal;
}

int main(){
    vector<string> race["Dwarf", "Elf", "Halfling", "Human", "Dragonborn", "Gnome", "Half-Elf", "Half-Orc", "Tiefling"];
    vector<string> charClass["Barbarian", "Bard", "Cleric", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard"];
    vector<string> allignment["Lawful Good", "Neutral Good", "Chaotic Good", "Lawful Neutral", "Neutral", "Chaotic Neutral", "Lawful Evil", "Neutral Evil", "Chaotic Evil"];
    vector<string> background["Acolyte", "Charlatan", "Criminal", "Entertainer", "Folk Hero", "Guild Artisan", "Hermit", "Noble", "Outlander", "Sailor", "Soldier", "Urchin"];
}
