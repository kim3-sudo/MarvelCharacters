/***************************************************************************                   
 * namelookup.cpp  -  Program to display name statistics                                       
 *                                                                                             
 * copyright : (C) 2017 by Jim Skon                                                            
 *                                                                            
 * This program create an index US Census name                                       
 * Data on the frequency of names in response to requestes.                           
 * It then allows you to look up any name, giving the 10 closest matches               
 *                                                            
 *     
 *
 ***************************************************************************/
#include "includes.h"
#include "CharacterProfile.h"
#include "CharacterNameMap.h"
#include "CharacterYearMap.h"

// Stuff for AJAX
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#define XML_USE_STL

using namespace std;
using namespace cgicc; // Needed for AJAX functions.

// File name for marvel data
const string fileName = "/home/class/SoftDev/marvel/marvel-wikia-data.csv";

void sendResults(vector<CharacterProfile> matchList);

int main() {
  // Object used for receiving AJAX call (and getting parameters)
  Cgicc cgi;    // Ajax object

  cout << "Content-Type: text/plain\n\n";
  
  // Build the name maps
  CharacterNameMap nameMap(fileName); 
  CharacterYearMap yearMap(fileName);
  vector<CharacterProfile> matchList; // place to stare the file locations of the matches
  
  // Create AJAX objects to receive information from web page.
  form_iterator itts = cgi.getElement("type_select");
  form_iterator itname = cgi.getElement("name");

  // Retrieve the actual paramaters
  string type = **itts;
  string search = **itname;
  
  //type = "Year";
  //search = "1984";	

  /* Convert search to upper case*/
  transform(search.begin(), search.end(), search.begin(), ::toupper);
  
  //cout << search << endl;
  
  /* send back the results */
  
  
  // Lookup the characters using the appropriate map
  if (type.compare("Year")==0) {
    matchList = yearMap.createCharacterList(search, fileName);
  } else if (type.compare("Name")==0){
    matchList = nameMap.createCharacterList(search, fileName);
  } 

  /*Characters are comma delimited*/
  sendResults(matchList);
  
return 0;
}


/*
Prints out character information. Data is used by namelookup.js. See the js function getMatches()

@param		vector<CharacterProfile>	matchList	List of character profiles that match the search. 
Data from each profile is printed 
@return		void

*/
void sendResults(vector<CharacterProfile> matchList)
{
	for (int i = 0; i < matchList.size(); i++) {
		
		cout << matchList.at(i).name << "," << matchList.at(i).identity << "," << matchList.at(i).alignment << ",";
		cout << matchList.at(i).eyeColor << "," << matchList.at(i).hairColor << "," << matchList.at(i).sex << ",";
		cout << matchList.at(i).sexualOrientation << "," << matchList.at(i).living << ",";
		cout << matchList.at(i).numOfAppearances << "," << matchList.at(i).firstAppearanceDate << ",";
		cout << matchList.at(i).firstAppearanceYear << "," << matchList.at(i).urlSlug;
		
		if (i<matchList.size()-1)
		{
			cout << ","; // Only put out this comma if not last entry.
		}
		
	}
}


