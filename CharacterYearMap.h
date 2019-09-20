#include "includes.h"
#include "CharacterProfile.h"

class CharacterYearMap 
{
  public:
    CharacterYearMap(string fileName);
    bool yearMapSuccess();
    vector<int> getCharacterIndecies(string confirmedName);

  private:
    map<string, vector<int>> yearMap;
    bool success;
};