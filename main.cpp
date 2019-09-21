#include "includes.h"
#include "userOut.h"
#include "charChar.h"
#include "charNameMap.h"
#include "charYearMap.h"

const string fileName = "MarvelCharacters";

vector<charChar> createCharacterList(string selectedName, charNameMap nameMap);
vector<charChar> createCharacterList(string year, charYearMap yearMap);

int main() {
  charNameMap nameMap(fileName);
  charYearMap yearmap(fileName);
	UserOutput output = UserOutput();
  output.dataload(nameMap.nameMapSuccess());
  output.dataload(yearmap.yearMapSuccess());

  bool validOption = false;
  while(validOption == false) {
    output.charLookup();
    int lookupChoice;
    cin >> lookupChoice;
    cout << "\n" << endl;

    if(lookupChoice == 1) {
      validOption = true;
      
      // get name from user
      output.askname();
      string name;
      cin >> name;
      transform(name.begin(), name.end(), name.begin(), ::toupper);

      // get name matches
      vector<string> nameMatchList = nameMap.getNameMatches(name);
      output.formatName(nameMatchList);
      int nameChoice;
      cin >> nameChoice;

      // invalid?
      if(nameChoice < 1 && nameChoice > 10) {
        output.invalid(nameChoice); 
      } else {
        // gets matches
        string selectedName = nameMatchList.at(nameChoice - 1);
        vector<charChar> charMatch;
        charMatch = createCharacterList(selectedName, nameMap);
        output.formatChar(charMatch);
        int charSelect;
        cin >> charSelect;
        output.showChar(charMatch.at(charSelect - 1));
      }
    } else if (lookupChoice == 2) {
      validOption = true;
      output.year();
      string year;
      cin >> year;
      vector<charChar> charMatch;
      charMatch = createCharacterList(year, yearmap);
      output.formatChar(charMatch);
      int charChoice;
      cin >> charChoice;
      output.showChar(charMatch.at(charChoice - 1));
    } else if (lookupChoice == 0) {
      return 0;
    } else {
      output.invalid(lookupChoice);
    }
  }
}

vector<charChar> createCharacterList(string selectedName, charNameMap nameMap) {
  vector<int> characterIndexes = nameMap.getCharacterIndexes(selectedName);
  vector<charChar> charMatch;
  for(int i = 0; i < characterIndexes.size(); i++) {
    charChar newCharacter = charChar(fileName, characterIndexes.at(i));
    charMatch.push_back(newCharacter);
  }
  return charMatch;
}

vector<charChar> createCharacterList(string year, charYearMap yearMap) {
  vector<int> characterIndexes = yearMap.getCharacterIndexes(year);
  vector<charChar> charMatch;
  for(int i = 0; i < characterIndexes.size(); i++) {
    charChar newCharacter = charChar(fileName, characterIndexes.at(i));
    charMatch.push_back(newCharacter);
  }
  return charMatch;
}