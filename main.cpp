#include "includes.h"
#include "userOut.h"
#include "charChar.h"
#include "charNameMap.h"
#include "charYearMap.h"

const string fileName = "MarvelCharacters";

int main() {
  charNameMap namemap(fileName);
  charYearMap yearmap(fileName);
 
	// create output interface
	UserOutput output = UserOutput();
	output.dataload(namemap.nameMapSuccess());
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
      output.name();
      string name;
      cin >> name;
      transform(name.begin(), name.end(), name.begin(), ::toupper);

      // get name matches
      vector<string> nameMatchList = namemap.getNameMatches(name);
      output.formatName(nameMatchList);
      int nameChoice;
      // gets name choice from user
      cin >> nameChoice;

      // invalid?
      if(nameChoice < 1 && nameChoice > 6) {
        output.invalid(nameChoice); 
      } else {
        // gets matches
        string selectedName = nameMatchList.at(nameChoice - 1);
        vector<charChar> charMatch;
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
      transform(year.begin(), year.end(), year.begin(), ::toupper);

      // get name matches
      vector<string> yearMatchList = yearmap.getYearMatches(year);
      int yearChoice;
      // gets name choice from user
      cin >> yearChoice;

      // invalid?
      if(yearChoice < 1 && yearChoice > 6) {
        output.invalid(yearChoice); 
      } else {
        // gets matches
        string selectedYear = yearMatchList.at(yearChoice - 1);
        vector<charChar> charMatch;
        output.formatChar(charMatch);
        int charSelect;
        cin >> charSelect;
        output.showChar(charMatch.at(charSelect - 1));
      }
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