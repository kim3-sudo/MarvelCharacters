#include "userOut.h"

void UserOutput::dataload(bool success) {
  if(success) {
    cout << "Data import success." << endl;
    cout << endl;
  } else {
    cout << "Data load failure!" << endl;
    cout << "\"If you're seeing this, the code is in what I thought was an unreachable state. I could give you advice for what to do. But honestly, why should you trust me? I clearly screwed this up. I'm writing a message that should never appear, yet I know it will probably appear someday. On a deep level, I know I'm not up to this task. I'm so sorry.\"" << endl;
    cout << "\t -Randall Munroe" << endl;
  }
}

void UserOutput::charLookup() {
  cout << "Lookup Marvel character data." << endl;
  select();
}

void UserOutput::select() {
  cout << "Select one: " << endl;
  cout << "\t" << "1. I know the character's name." << endl;
  cout << "\t" << "2. I know when the character first appeared in the Marvel comic universe." << endl;
  cout << "\t" << "0. Get me out of here! (Exit)" << endl;
}

void UserOutput::name() {
  cout << "Enter name search query: ";
}

void UserOutput::year() {
  cout << "Enter year search query: ";
}

void UserOutput::invalid(string invalidString) {
  cout << invalidString + " is an invalid option." << endl;
}

void UserOutput::invalid(double invalidNumber) {
  cout << invalidNumber << " is an invalid option." << endl;
}

void UserOutput::formatName(vector<string> matchList) {
  cout << "Here are the six closest matches to the name you entered." << endl;
  cout << "\t" << "1." + matchList.at(0) << endl;
  cout << "\t" << "2." + matchList.at(1) << endl;
  cout << "\t" << "3." + matchList.at(2) << endl;
  cout << "\t" << "4." + matchList.at(3) << endl;
  cout << "\t" << "5." + matchList.at(4) << endl;
  cout << "\t" << "6." + matchList.at(5) << endl;
  cout << "\n";
}

void UserOutput::formatChar(vector<charChar> characterList) {
  cout << endl;
  cout << "Search Results: " << endl;
  cout << "\n";
  for(int i = 0; i < characterList.size() - 1; i++) {
    charChar character = characterList.at(i);
    cout << "\t" << i+1 << "." << character.name << endl; 
  }
  charSelect();
}

void UserOutput::charSelect() {
  cout << "Select character to view." << endl;
}

void UserOutput::showChar(charChar marvelCharacter) {
  cout << "\n" + marvelCharacter.name + ": " + marvelCharacter.identity + ", " + marvelCharacter.alignment + ", " + marvelCharacter.eyeColor + ", " + marvelCharacter.hairColor + ", " + marvelCharacter.sex + ", " + marvelCharacter.sexualOrientation + ", " + marvelCharacter.living + ", " + marvelCharacter.numOfAppearances+ " appearances. \nFirst appearance: " + marvelCharacter.firstAppearanceDate + ", " + marvelCharacter.firstAppearanceYear + "." << endl;
}