#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Character.h"
#include <fstream>
#include <string>
using namespace std;

//rolls dice
int diceRoll(int numDice, int sidesDice){
    int diceTotal = 0;
    for(int i = 0; i < numDice; i++){
        diceTotal = (rand()%sidesDice+1) + diceTotal;
    }
    return diceTotal;
}

//performs a standard dnd stat roll
int statRoll(){
    int rolls[4];
    for (int i = 0; i < 4; i++){
        rolls[i] = diceRoll(1,6);
    }
    int minRoll = 7;
    for (int i = 0; i < 4; i++){
        if (rolls[i] < minRoll){
            minRoll = rolls[i];
        }
    }
    int sumRoll = 0;
    for (int i = 0; i < 4; i++){
        sumRoll = sumRoll + rolls[i];
    }
    return sumRoll - minRoll;
}

int main(){

    //seeding the random number generator
    srand(time(NULL));

    // Initialization of some important variables
    string race[] = {"Dwarf", "Elf", "Halfling", "Human", "Dragonborn", "Gnome", "Half-Elf", "Half-Orc", "Tiefling"};
    int numRaces = 9;
    string charClass[] = {"Barbarian", "Bard", "Cleric", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard"};
    int numClass = 12;
    string alignment[] = {"Lawful Good", "Neutral Good", "Chaotic Good", "Lawful Neutral", "Neutral", "Chaotic Neutral", "Lawful Evil", "Neutral Evil", "Chaotic Evil"};
    int numAli = 9;
    string background[] = {"Acolyte", "Charlatan", "Criminal", "Entertainer", "Folk Hero", "Guild Artisan", "Hermit", "Noble", "Outlander", "Sailor", "Soldier", "Urchin"};
    int numBack = 12;

    Character myChar;
    string userStringInput = "null";
    int userIntInput = 0;

    //setting race
    cout << "Please choose your character's race. Or, have the program randomize it by typing \"random\" and pressing ENTER\n";
    cin >> userStringInput;
    if (userStringInput == "random" || "Random" || "R" || "RANDOM" || "Rand" || "rand"){
        myChar.raceSet(race[diceRoll(1,numRaces)-1]);
    }
    else {
        myChar.raceSet(userStringInput);
    }
    cout << "Perfect, your character is now a mighty " << myChar.raceGet() << endl;

    //setting class
    cout << "Please choose your character's class. Or, have the program randomize it by typing \"random\" and pressing ENTER\n";
    cin >> userStringInput;
    if (userStringInput == "random" || "Random" || "R" || "RANDOM" || "Rand" || "rand"){
        myChar.classSet(charClass[diceRoll(1,numClass)-1]);
    }
    else {
        myChar.classSet(userStringInput);
    }
    cout << "Perfect, your character is now a skilled " << myChar.classGet() << endl;

    //setting alignment
    cout << "Please choose your character's Alignment. Or, have the program randomize it by typing \"random\" and pressing ENTER\n";
    cin >> userStringInput;
    if (userStringInput == "random" || "Random" || "R" || "RANDOM" || "Rand" || "rand"){
        myChar.aliSet(alignment[diceRoll(1,numAli)-1]);
    }
    else {
        myChar.aliSet(userStringInput);
    }
    cout << "Perfect, your character is now aligned as " << myChar.aliGet() << endl;

    //setting background
    cout << "Please choose your character's Background. Or, have the program randomize it by typing \"random\" and pressing ENTER\n";
    cin >> userStringInput;
    if (userStringInput == "random" || "Random" || "R" || "RANDOM" || "Rand" || "rand"){
        myChar.backSet(background[diceRoll(1,numBack)-1]);
    }
    else {
        myChar.backSet(userStringInput);
    }
    cout << "Perfect, your character was a(n) " << myChar.backGet() << " before they were an adventurer" << endl;

    //setting gender
    cout << "Choose your character's gender. Or, have the program randomize it by typing \"random\" and pressing ENTER\n";
    cin >> userStringInput;
    if (userStringInput == "random" || "Random" || "R" || "RANDOM" || "Rand" || "rand"){
            int genNum = diceRoll(1,2);
            if (genNum == 1){
                myChar.genderSet("Male");
            }
            if (genNum == 2){
                myChar.genderSet("Female");
            }
    }
    else{
        myChar.genderSet(userStringInput);
    }
    cout << "Your character is a proud " << myChar.genderGet() << endl;

    //needed for some reason in order to let getline work
    cin.clear();
    cin.ignore(99999999, '\n');

    //Set name
    cout << "What is the name of your brave adventurer?" << endl;
    string name;
    getline(cin, name);
    myChar.nameSet(name);
    cout << myChar.nameGet() << ", a name for a true hero!" << endl;

    cout << "The program will now roll stats for you. It will roll 4 imaginary dice and subtract the lowest dice roll from each set!\n";
    for (int i = 0; i < 6; i++){
        myChar.statsSet(i, statRoll());
    }
    //display stats and their "number" for changing one stat to 18
    cout << "Strength: " << myChar.statsGet(0) << " \t\t\t (1)" << endl;
    cout << "Dexterity: " << myChar.statsGet(1) << " \t\t\t (2)" << endl;
    cout << "Constitution: " << myChar.statsGet(2) << " \t\t (3)" << endl;
    cout << "Intelligence: " << myChar.statsGet(3) << " \t\t (4)" << endl;
    cout << "Wisdom: " << myChar.statsGet(4) << " \t\t\t (5)" << endl;
    cout << "Charisma: " << myChar.statsGet(5) << " \t\t\t (6)" << endl;

    cout << "\n\nPlease choose one stat to replace with an 18 (1 through 6)\n";
    cin >> userIntInput;
    myChar.statsSet(userIntInput-1,18);
    cout << "The stat has been replaced" << endl << endl << endl;

    //File creation
    ofstream charFile;
    string filename = myChar.nameGet() + ".txt";
    charFile.open(filename);

    //file output
    charFile << "Character Name: " << myChar.nameGet() << endl;
    charFile << " - Gender: " << myChar.genderGet() << endl;
    charFile << " - Race: " << myChar.raceGet() << endl;
    charFile << " - Class: " << myChar.classGet() << endl;
    charFile << " - Background: " << myChar.backGet() << endl;
    charFile << " - Alignment: " << myChar.aliGet() << endl;

    charFile << "\n\n --STATS-- \n\n\n";

    charFile << "Strength: " << myChar.statsGet(0) << endl;
    charFile << "Dexterity: " << myChar.statsGet(1) << endl;
    charFile << "Constitution: " << myChar.statsGet(2) << endl;
    charFile << "Intelligence: " << myChar.statsGet(3) << endl;
    charFile << "Wisdom: " << myChar.statsGet(4) << endl;
    charFile << "Charisma: " << myChar.statsGet(5) << endl << endl << endl;
    charFile << "Remember to finish your character by using a Dungeons and Dragons 5th Edition \"Player's Handbook\"" << endl;

    charFile.close();

    //notify the user that the program has finished running
    cout << "Character file completed! It is named " << filename << " and can be found within the program folder!";
}
