#include "UserOutput.h"

void UserOutput::informDataSuccess(bool success) {
  if(success) {
    cout << "Name data loaded.\n" << endl;
  } else {
    cout << "Failure to load data.\n" << endl;
  }
}

void UserOutput::promptCharacterLookup() {
  cout << "Lookup Marvel character data." << endl;
  askNameOrYear();
}

void UserOutput::askNameOrYear() {
  cout << "Select one:\n\t1) Search by Name\n\t2) Search by Year of First Apperance" << endl;
}

void UserOutput::askName() {
  cout << "\n";
  cout << "Search by name name: " << endl;
}

void UserOutput::askYear() {
  cout << "\n";
  cout << "Search by year: " << endl;
}

void UserOutput::informInvalidOption(string invalidString) {
  cout << "\n";
  cout << invalidString + " is an invalid option." << endl;
}

void UserOutput::informInvalidOption(double invalidNumber) {
  cout << "\n";
  cout << invalidNumber << " is an invalid option." << endl;
}

void UserOutput::formatNameMatches(vector<string> matchList) {
  cout << "\nHere are the six closest matches to the name you entered.\n";
  cout << "\n\t1)" + matchList.at(0) + "\n\t2)" + matchList.at(1) + "\n\t3)" + matchList.at(2) + "\n\t4)" + matchList.at(3) + "\n\t5)" + matchList.at(4) + "\n\t6)" + matchList.at(5) + "\n" << endl;
  confirmNameChoice();
}

void UserOutput::confirmNameChoice() {
  cout << "Please confirm the name you are searching for by selcting from one of the above names." << endl;
}

void UserOutput::formatCharacterMatches(vector<CharacterProfile> characterList) {
  cout << "\n";
  cout << "Here are the Marvel characters that match your search\n" << endl;
  for(int i = 0; i < characterList.size() - 1; i++) {
    CharacterProfile character = characterList.at(i);
    cout << "\t" << i+1 << ")" << character.name << endl; 
  }
  askCharacterChoice();
}

void UserOutput::askCharacterChoice() {
  cout << "\nWhich character profile would you like to view?" << endl;
}

void UserOutput::presentCharacterInfo(CharacterProfile marvelCharacter) {
  cout << "\n" + marvelCharacter.name + ": " + marvelCharacter.identity + ", " + marvelCharacter.alignment + ", " + marvelCharacter.eyeColor + ", " + marvelCharacter.hairColor + ", " + marvelCharacter.sex + ", " + marvelCharacter.sexualOrientation + ", " + marvelCharacter.living + ", " + marvelCharacter.numOfAppearances+ " appearances. \nFirst appearance: " + marvelCharacter.firstAppearanceDate + ", " + marvelCharacter.firstAppearanceYear + "." << endl;
}