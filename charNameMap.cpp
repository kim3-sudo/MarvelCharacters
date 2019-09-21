#include "charNameMap.h"

charNameMap::charNameMap(string fileName) {
  string name; // important name
  string line;
  string page_id;
  string fullName;

  fstream infile(fileName); // opens fileName for input
  int position = 1;
  //getline(infile, line); // ignore 0 header, no char data
  if(infile.good()) {
    while(true) {
      char delim = ','; // wait until we run out of commas
      getline(infile, page_id, delim);
      getline(infile, fullName, delim);

      char characterData[fullName.size() +1];
      strcpy(characterData, fullName.c_str());
      
      char delims[] = " ()\"";
      char * name;
      name = strtok(characterData, delims); // string token
      while(name != NULL) {
        cout << name << endl;
        nameMap[name].push_back(position);
        name = strtok(NULL, delims);
      }
      getline(infile, line);
      if(infile.fail()) {
        break;
      }
      position = infile.tellg(); //Get the position of the next line (Get the line number)
    }
    infile.close(); // Close the file
    success = true; // Report that map creation was a success
  } else {
    success = false; 
  }
}

bool charNameMap::nameMapSuccess() {
  return success;
}

vector<string> charNameMap::getNameMatches(string name) {
    vector<string> matchList;
    string match; // holds matching character strings
    map<string, vector<int>>::iterator nameiterator; // make iterator 
    nameiterator = nameMap.lower_bound(name); // set iterator to closest match

    // back up to 2 places or to the beginning of the map.
    for (int i = 0; i < 2 && (nameiterator != nameMap.begin()); i++) {
      --nameiterator;
    }

    // Get up to 10 closest results
    for (int i = 0; i < 10 && (nameiterator != nameMap.end()); i++) {
      match = (*nameiterator).first; // Set match to the name value in the map pointed to by our iterator
      matchList.push_back(match); // Add match to our matchlist
      nameiterator++; // Move to the next result
    }
    return matchList; //Returns 6 closest names
}

vector<int> charNameMap::getCharacterIndexes(string confirmedName) {
  vector<int> profileLocations; // Create int vector to hold profile locations
  profileLocations = nameMap.at(confirmedName); //Set our new vector to the value of the vector in our map, mapped from the name "confirmedName".
  return profileLocations; // Return all locations of characters with the name "confirmedName"
}