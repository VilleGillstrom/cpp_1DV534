#pragma once
#include <vector>
#include <string>

class Texthandler
{
public:
	Texthandler(const char* filename, int size);						// Read filename into _text, size is max entries 
	~Texthandler();


	const size_t MAX_TEXT_LEN = 10000;									// Will exit if text length is over this

	
	int nrOfTexts() const;												// Number of text in Texthandler 
	int maxNrOfTexts() const;											// Maximum number of text Texthandler can store 
	const char* text(int index) const;									// Retrieve a text by index 


private:
	std::vector<char*> _texts;											//Store individual texts 


	bool readTextsFromFile(const char* filename);						// Read a file into _texts
	void addStringToTexts(const std::string& textBuffer, int index);	// Convert a string to char* and store it in _texts
	
};
