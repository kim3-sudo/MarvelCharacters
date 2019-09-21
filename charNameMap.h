#include "includes.h"
#include "charChar.h"

class charNameMap {
  public:
    charNameMap(string fileName);
    bool nameMapSuccess();
    vector<string> getNameMatches(string name);
    vector<int> getCharacterIndexes(string confirmedName);
  private:
    map<string, vector<int>> nameMap;
    bool success;
    void mapNamePos(char charName[], int pos);
};