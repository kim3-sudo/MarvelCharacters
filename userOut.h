#include "includes.h"
#include "charChar.h"

class UserOutput {
  public:
  void dataload(bool success);
  void charLookup();
  void name();
  void year();
  void invalid(string invalidString);
  void invalid(double invalidNumber);
  void formatName(vector<string> matchList);
  void formatChar(vector<charChar> characterList);
  void showChar(charChar marvelCharacter);
  private:
  void select();
  void charSelect();
};