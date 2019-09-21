#include "includes.h"
#include "charChar.h"

class charYearMap {
  public:
    charYearMap(string fileName);
    bool yearMapSuccess();
    vector<string> getYearMatches(string firstAppearanceYear);
    vector<int> getCharacterIndexes(string confirmedName);
  private:
    map< string, vector<int> > yearMap;
    bool success;
};