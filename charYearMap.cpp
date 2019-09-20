#include "includes.h"
#include "charYearMap.h"

charYearMap::charYearMap(string fileName) {
  string year; // Each year component to be searched for
  string line; // Holds the rest of the data in the line that we aren't concerned about

  fstream infile(fileName); // Opens "fileName" for input
  int position = 1;
  //getline(infile, line); // Store first line in database which does not give character data
  if(infile.good()) {
    /* Keep going until we reach the end of the file */
    while(true) {
      char delim = ',';
      getline(infile, year, delim);
      char characterData[year.size() +1];
      strcpy(characterData, year.c_str());
      char delims[] = " ()\"";


      char * year;
      year = strtok(characterData, delims);
      while(year != NULL) {
        cout << year << endl;
        yearMap[year].push_back(position);
        year = strtok(NULL, delims);
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

bool charYearMap::yearMapSuccess() {
  return success;
}

vector<string> charYearMap::getYearMatches(string year) {
    vector<string> matchList; // vector to hold closest matches
    string match; // Holds each individual match.
    // Look up the closest lower match
    map<string, vector<int>>::iterator it; // Create iterator for our map 
    it = yearMap.lower_bound(year); // Set iterator to closest match for year

    // back up (up to) 3 places or to the beginning of the map.
    for (int i = 0; i < 3 && (it != yearMap.begin()); i++) {
      --it;
    }

    // Get (up to) 6 closest results
    for (int i = 0; i < 6 && (it != yearMap.end()); i++) {
      match = (*it).first; // Set match to the year value in the map pointed to by our iterator
      matchList.push_back(match); // Add match to our matchlist
      it++; // Move to the next result
    }
    return matchList; //Returns 6 closest years
}

vector<int> charYearMap::getCharacterIndexes(string confirmedYear) {
  vector<int> profileLocations; // Create int vector to hold profile locations
  profileLocations = yearMap.at(confirmedYear); //Set our new vector to the value of the vector in our map, mapped from the year "confirmedYear".
  return profileLocations; // Return all locations of characters with the year "confirmedYear"
}