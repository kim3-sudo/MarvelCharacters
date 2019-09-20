#include "includes.h"
#ifndef CHARACTERPROFILE_H
#define CHARACTERPROFILE_H

class CharacterProfile 
{
  public:
  CharacterProfile(string fileName, int lineNumber);
  
  string name; // character name
  string identity; // secret, public
  string alignment; // good, bad, neutral
  string eyeColor; // eye color
  string hairColor; // hair color
  string sex; // male, female
  string sexualOrientation; // :)
  string living; // dead, alive
  string numOfAppearances; // num of comic book appearances
  string firstAppearanceDate; // MMM-DD
  string firstAppearanceYear; // YYYY
  private:
  //We are not using these variables in our code
  string page_id; 
  string urlSlug;
};

#endif