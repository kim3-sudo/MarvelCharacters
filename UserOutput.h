#include "includes.h"
#include "CharacterProfile.h"

class UserOutput {
  public:
  void informDataSuccess(bool success);
  void promptCharacterLookup();
  void askName();
  void askYear();
  void informInvalidOption(string invalidString);
  void informInvalidOption(double invalidNumber);
  void formatNameMatches(vector<string> matchList);
  void formatCharacterMatches(vector<CharacterProfile> characterList);
  void presentCharacterInfo(CharacterProfile marvelCharacter);
  private:
  void askNameOrYear();
  void confirmNameChoice();
  void askCharacterChoice();
};