#include "includes.h"
//#include "import.h"
#include "UserOutput.h"
#include "CharacterNameMap.h"
#include "CharacterProfile.h"

const string fileName = "MarvelCharacters.csv";

int main() {
  // create name map
  CharacterNameMap namemap(fileName);
 
	// create output interface
	UserOutput output = UserOutput();
	output.informDataSuccess(namemap.nameMapSuccess());

  bool validOption = false;
  while(validOption == false) {
    output.promptCharacterLookup();
    int lookupChoice;
    cin >> lookupChoice;

    if(lookupChoice == 1)
    {
      validOption = true;
      
      //Gets name from user
      output.askName();
      string name;
      cin >> name;
      transform(name.begin(), name.end(), name.begin(), ::toupper);

      //Gets name matches
      vector<string> nameMatchList = namemap.getNameMatches(name);
      output.formatNameMatches(nameMatchList);
      int nameChoice;
      //Gets name choice from user
      cin >> nameChoice;

      //If their choice was not valid inform them else continue
      if(nameChoice < 1 && nameChoice > 6)
      {
        output.informInvalidOption(nameChoice); 
      }
      else
      {
        //Gets character matches
        string selectedName = nameMatchList.at(nameChoice - 1);
        vector<CharacterProfile> characterMatches;
        //characterMatches = createCharacterList(selectedName, namemap);
        output.formatCharacterMatches(characterMatches);
        int characterChoice;
        cin >> characterChoice;

        output.presentCharacterInfo(characterMatches.at(characterChoice - 1));
      }
    }
    else if (lookupChoice == 2)
    {
      validOption = true;

      output.askYear();
    }
    else
    {
      output.informInvalidOption(lookupChoice);
    }
  }



}


/*
Creates a vector of character profiles that match the name searched for by the user.

@param  string selectedName The name of the character being searched for
@param  CharacterNameMap nameMap  Name map mapping name to lines in the file containing that name
@return vector<CharacterProfile>  Vector containing a character profile for each character that matches the name searched
*/
vector<CharacterProfile> createCharacterList(string selectedName, CharacterNameMap nameMap)
{
  vector<int> characterIndecies = nameMap.getCharacterIndecies(selectedName);
  vector<CharacterProfile> characterMatches;
  for(int i = 0; i < characterIndecies.size(); i++)
  {
    CharacterProfile newCharacter = CharacterProfile(fileName, characterIndecies.at(i));
    characterMatches.push_back(newCharacter);
  }
  return characterMatches;
}