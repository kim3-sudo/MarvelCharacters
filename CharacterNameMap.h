#pragma once
#include "includes.h"

class CharacterNameMap 
{
  public:
    CharacterNameMap(string fileName);
    bool nameMapSuccess();
    vector<string> getNameMatches(string name);
    vector<int> getCharacterIndecies(string confirmedName);

  private:
    map< string, vector<int> > nameMap;
    bool success;
};