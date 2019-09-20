#include "charChar.h"
charChar::charChar(string fileName, int lineNumber) {
  fstream infile(fileName);
  infile.seekg(lineNumber, infile.beg);
  // string containing all character profile data
  string profileData;
  getline(infile, profileData);
  istringstream characterStream(profileData);
  // parse stream by comma delim, stores each characteristic in its respective variable
  getline(characterStream, page_id, ',');
  getline(characterStream, name, ',');
  getline(characterStream, urlSlug, ',');
  getline(characterStream, identity, ',');
  getline(characterStream, alignment, ',');
  getline(characterStream, eyeColor, ',');
  getline(characterStream, hairColor, ',');
  getline(characterStream, sex, ',');
  getline(characterStream, sexualOrientation, ',');
  getline(characterStream, living, ',');
  getline(characterStream, numOfAppearances, ',');
  getline(characterStream, firstAppearanceDate, ',');
  getline(characterStream, firstAppearanceYear, ',');
}