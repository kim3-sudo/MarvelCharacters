#include "includes.h"
#include "import.h"

using namespace std;

const string path = "";
const string lastFile = path+"MarvelCharacters.csv";


/* Server main line,create name MAP, wait for and serve requests */
int main() {
    // Create object of csvread
    csvread reader("MarvelCharacters");
    // Get the data from CSV File
	std::vector<std::vector<std::string> > dataList = reader.getData();
 
	// Print the content of row by row on screen
	for(std::vector<std::string> vec : dataList)
	{
		for(std::string data : vec)
		{
			std::cout<<data << " , ";
		}
		std::cout<<std::endl;
	}
	return 0;
}