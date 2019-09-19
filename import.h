#pragma once
#include "includes.h"

class csvread
{
	std::string fileName;
	std::string delimiter;
 
public:
	csvread(std::string filename, std::string delm = ",") :
			fileName(filename), delimiter(delm)
	{ }
 
	// Function to fetch data from a CSV File
	std::vector<std::vector<std::string> > getData();
};
 
// Parses through csv file line by line and returns the data in vector of vector of strings.

std::vector<std::vector<std::string> > csvread::getData()
{
	std::ifstream file(fileName);
 
	std::vector<std::vector<std::string> > dataList;
 
	std::string line = "";
	// Iterate through each line and split the content using delimiter
	while (getline(file, line))
	{
		std::vector<std::string> vec;
		dataList.push_back(vec);
	}
	// Close the File
	file.close();
 
	return dataList;
}