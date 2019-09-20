#include "CharacterNameMap.h"
CharacterNameMap::CharacterNameMap(string fileName) {
  string name;
  string fullName;
  string line;
  string page_id;
  fstream infile(fileName);
  int position = 1;
  if(infile.good()) {
    while(true) {
      char delim = ',';
      getline(infile, page_id, delim);
      getline(infile, fullName, delim);
      cout << "Full:" << fullName <<  endl;
      char characterData[fullName.size() +1];
      strcpy(characterData, fullName.c_str());
      char delims[] = " ()\"";
      char * name;
      name = strtok(characterData, delims);
      while(name != NULL)
      {
        cout << name << endl;
        nameMap[name].push_back(position);
        name = strtok(NULL, delims);
      }
      getline(infile, line);
      if(infile.fail()) {
        break;
      }
      position = infile.tellg();
    }
    infile.close();
    success = true;
  } else {
    success = false;
  }
}

bool CharacterNameMap::nameMapSuccess() {
  return success;
}
vector<string> CharacterNameMap::getNameMatches(string name) {
    vector<string> matchList; // vector to hold closest matches
    string match; // Holds each individual match.
    // Look up the closest lower match
    map< string, vector<int> >::iterator it; // Create iterator for our map 
    it = nameMap.lower_bound(name); // Set iterator to closest match for name

    // back up (up to) 3 places or to the beginning of the map.
    for (int i = 0; i < 3 && (it != nameMap.begin()); i++) 
    {
      --it;
    }

    // Get (up to) 6 closest results
    for (int i = 0; i < 6 && (it != nameMap.end()); i++) 
    {
      match = (*it).first; // Set match to the name value in the map pointed to by our iterator
        //Could also use (*it)->first?
      matchList.push_back(match); // Add match to our matchlist
      it++; // Move to the next result
    }
    return matchList; //Returns 6 closest names
}


/*
Gets the characters that correspond to the name searched for. 
Uses the CharacterNameMap to lookup the vector of line numbers that reference the character's name.
Each line contains all of the information in a character's profile.

@param  string characterName  The name of the the character that the user wants to lookup.
We use getNameMatches() to make sure the name the user inputs exists if not they are allowed to choose the closest one. 
  Prevents program errors due to user errors typos
@return vector<int> profileLocations  The list of line locations for character profiles/data that contain the name searched for.
*/
vector<int> CharacterNameMap::getCharacterIndecies(string confirmedName)
{
  vector<int> profileLocations; // Create int vector to hold profile locations
  profileLocations = nameMap.at(confirmedName); //Set our new vector to the value of the vector in our map, mapped from the name "confirmedName".

  return profileLocations; // Return all locations of characters with the name "confirmedName"
}