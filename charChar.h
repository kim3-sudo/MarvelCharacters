#include "includes.h"
#ifndef CHARACTERPROFILE_H
#define CHARACTERPROFILE_H

class charChar {
  public:
    charChar(string fileName, int lineNumber);
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
    string page_id; 
    string urlSlug;
};

#endif