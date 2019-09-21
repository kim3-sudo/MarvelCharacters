#include "charYearMap.h"

charYearMap::charYearMap(string fileName) {
  string year; // Each year component to be searched for
  string line; // Holds the rest of the data in the line that we aren't concerned about

  fstream infile(fileName); // Opens "fileName" for input
  int position = 1;
  //getline(infile, line); // ignore 0 header, no char data
  if(infile.good()) {
    // Keep going until we reach the end of the file
    while(true) {
      char delim = ',';
      string junk;
      for(int i = 0; i < 12; i++) {
        getline(infile, junk, delim);
      }
      infile >> year;
      yearMap[year].push_back(position);
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

vector<int> charYearMap::getCharacterIndexes(string confirmedYear) {
  vector<int> profileLocations; // Create int vector to hold profile locations
  profileLocations = yearMap.at(confirmedYear); //Set our new vector to the value of the vector in our map, mapped from the year "confirmedYear".
  return profileLocations; // Return all locations of characters with the year "confirmedYear"
}