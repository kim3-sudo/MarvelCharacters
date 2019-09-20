#include "CharacterProfile.h"
CharacterProfile::CharacterProfile(string fileName, int lineNumber)
{
  // Set file input stream to "fileName"
  fstream infile(fileName);
  // Set position of beginning of stream to "lineNumber"
  infile.seekg(lineNumber, infile.beg);

  // string containing all character profile data
  string profileData;
  // store line with all character data into profileData
  getline(infile, profileData);
  // create string stream
  istringstream characterStream(profileData);

  // Parse string stream by comma delimitor, stores each characteristic in its respective variable
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