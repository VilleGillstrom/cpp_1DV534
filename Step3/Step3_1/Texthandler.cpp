#include "Texthandler.h"
#include <fstream>
#include <string>
#include <iostream>

Texthandler::Texthandler(const char* filename, int size) 
{
	_texts.resize(size);
	if(!readTextsFromFile(filename))
	{
		std::cerr << "Unable to read file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

Texthandler::~Texthandler()
{
	// free memory
	for (char* text : _texts)
	{
		delete[] text;
	}
}

int Texthandler::nrOfTexts() const
{
	int count = 0;

	// Count the nr of texts in texts by non-nullptrs
	for (char* text : _texts)
	{
		if (text != nullptr)
		{
			count++;
		}
	}
	return count;
}

int Texthandler::maxNrOfTexts() const
{
	return _texts.size();
}

const char* Texthandler::text(int index) const
{
	// Validate index
	if (index < 0 || index > maxNrOfTexts())
	{
		return nullptr;
	}
	return _texts[index];
}

void Texthandler::addStringToTexts(const std::string& textBuffer, int index)
{
	const int textLen = textBuffer.size();
	char* text = new char[textLen + 1]();
	textBuffer.copy(text, textLen);
	_texts[index] = text;
}

bool Texthandler::readTextsFromFile(const char* filename)
{
	std::ifstream file(filename);
	if (file.fail())
	{
		return false;		/* Unable to open file */
	}

	int index = 0;			/* What text nr we are reading */
	std::string line;		/* Temporary buffer for a line */
	std::string textBuffer; /* Temporary buffer for a text */

	// file starts with %%%%%, so just read it 
	std::getline(file, line);
	while (std::getline(file, line))
	{
		/* Check for text end */
		if (line == "%%%%%")
		{
			/* Allocate memory and copy textBuffer */
			addStringToTexts(textBuffer, index);
			textBuffer.clear();
			index++;
		}
		else
		{
			//Keep storing lines into buffer
			textBuffer.append(line);
			textBuffer.append("\n");

			//Check against too long text
			if(textBuffer.size() > MAX_TEXT_LEN)
			{
				std::cerr << "Text length exceeds maximum. Exiting";
				std::exit(EXIT_FAILURE);
			}
		}
	}

	file.close();
	return true;
}
