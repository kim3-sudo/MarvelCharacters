#include "includes.h"
#include "charNameMap.h"

charNameMap::charNameMap(string fileName) {
  string name; // Each name component to be searched for
  string fullName; // The full name to be searched for and parsed into name components
  string line; // Holds the rest of the data in the line that we aren't concerned about
  string page_id; // Data at the beginning of the line, not relevant to mapping names 

  fstream infile(fileName); // Opens fileName for input
  int position = 1;
  //getline(infile, line); // ignore 0 header, no char data
  if(infile.good()) {
    while(true) {
      char delim = ','; // wait until we run out of commas
      getline(infile, page_id, delim);
      getline(infile, fullName, delim);
      cout << "Full:" << fullName <<  endl;
      char characterData[fullName.size() +1];
      strcpy(characterData, fullName.c_str());
      char delims[] = " ()\"";
      //Need initializer list or string literal
      //Cannot use variable
      char * name;
      name = strtok(characterData, delims);
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
    vector<string> matchList; // vector to hold closest matches
    string match; // Holds each individual match.
    // Look up the closest lower match
    map< string, vector<int> >::iterator it; // Create iterator for our map 
    it = nameMap.lower_bound(name); // Set iterator to closest match for name

    // back up (up to) 3 places or to the beginning of the map.
    for (int i = 0; i < 3 && (it != nameMap.begin()); i++) {
      --it;
    }

    // Get (up to) 6 closest results
    for (int i = 0; i < 6 && (it != nameMap.end()); i++) {
      match = (*it).first; // Set match to the name value in the map pointed to by our iterator
      matchList.push_back(match); // Add match to our matchlist
      it++; // Move to the next result
    }
    return matchList; //Returns 6 closest names
}

vector<int> charNameMap::getCharacterIndexes(string confirmedName) {
  vector<int> profileLocations; // Create int vector to hold profile locations
  profileLocations = nameMap.at(confirmedName); //Set our new vector to the value of the vector in our map, mapped from the name "confirmedName".
  return profileLocations; // Return all locations of characters with the name "confirmedName"
}