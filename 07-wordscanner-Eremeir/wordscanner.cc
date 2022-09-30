/*
Matt Borek (z1951125)
Assignment 07
03/21/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <utility>
#include <sstream>
#include <iomanip>

const int NO_ITEMS = 4;
const int ITEM_WORD_WIDTH = 14;
const int ITEM_COUNT_WIDTH = 3;

/**
 * @brief Clean dictionary entry
 * 
 * Cleans the given raw input string of all punctuation and translates it to all lowercase characters. This is called within get_words().
 * 
 * @param rawWord Initial unedited word, used in testing and scanning for positions to construct pureWord.
 * @param pureWord Cleaned and final edited version of rawWord, ready for insertion to the dictionary map.
 */
void clean_entry(const std::string &rawWord, std::string &pureWord)
{
    auto position1 = std::find_if(rawWord.begin(), rawWord.end(), [rawWord](char testChar){return (isalnum(testChar));}); //Find the position of the first alphanumeric char.
    auto position2 = std::find_if(position1, rawWord.end(), [rawWord](char testChar){return (!isalnum(testChar));}); //Find the position of the first non-alphanumeric char.

    if (position1 != position2) //If both positions are equal, then the entire word is non-alphanumeric or blank.
    {
        std::string cleanedWord(position1, position2); //Construct a string object from the chars inbetween both positions.
        for_each(cleanedWord.begin(), cleanedWord.end(), [cleanedWord](char &letter){letter = tolower(letter);}); //Translate each character to lowercase.
        pureWord = cleanedWord;
    }
}

/**
 * @brief Read words from input
 * 
 * Reads line by line from user input and seperates individual raw words from each line to be cleaned by clean_entry().
 * Once cleaned, add the word to the dictionary map.
 * 
 * @param wordMap The word dictionary map to add cleaned words to.
 */
void get_words(std::map<std::string, int> &wordMap)
{
    bool inputClosed = false;

    while(!inputClosed)
    {
        std::string tempLine;
        std::getline(std::cin, tempLine); //Accept user input line by line and stores in tempLine.
        
        if(tempLine.length() != 0) //Ensure the input isn't blank.
        {
            std::string tempWord;
            std::string finalWord;

            std::stringstream line(tempLine); //Create a stringstream object from the line.
            while (line >> tempWord) //Extract words one by one from the stringstreamobject.
            {
                clean_entry(tempWord, finalWord); //Call clean_entry() to clean dictionary word and fill finalWord with cleaned variant.
                if (finalWord.length() != 0) //Do not add blank words, if somehow created, to the dictionary map.
                {
                    wordMap[finalWord]++; //Add word to map and increase word occurences.
                }
            }
        }
        else
        {
            inputClosed = true; //Signals that there is no more input to process.
        }
    }
}

/**
 * @brief Print grid of dictionary words.
 * 
 * Prints out words from the dictionary words into a grid which is dynamically formatted by several variables.
 * 
 * @note NO_ITEMS is the number of words to include in a single line of grid output.
 * @note ITEM_WORD_WIDTH is the width spacing for words.
 * @note ITEM_COUNT_WIDTH is the width spacing for word occurences.
 * 
 * @param wordMap The word dictionary map to print words from.
 */
void print_words(const std::map<std::string, int> &wordMap)
{
    unsigned inputWordCount = 0;
    unsigned indentCount = 0;
    for(auto &i : wordMap)
    {
        ++indentCount;
        inputWordCount += i.second; //Sum up each word occurence to arrive at the toal number of input words.
        std::cout << std::setw(ITEM_WORD_WIDTH) << std::left << i.first << ":" << std::setw(ITEM_COUNT_WIDTH) << i.second; //Print Word     :Occurences

        if(indentCount % NO_ITEMS == 0 || indentCount == wordMap.size()) //Indent the output stream every NO_ITEMS words.
        {
            std::cout << std::endl;
        }
    }
    std::cout << "number of words in input stream   :" <<  inputWordCount << std::endl << "number of words in output stream  :" << wordMap.size() << std::endl;
}

/**
 * @brief Accept user input on words to clean and store in the dictionary.
 * 
 * Accept a properly formatted input line by line, and parse that input to call remove punctuation and clean words to base form.
 * Then print output into a dynamic stream and report word counts.
 * 
 * @return int 0 to close program out of scope.
 */
int main()
{
    std::map<std::string, int> wordMap; //Create wordMap.

    get_words(wordMap); //Get, clean, and add words to dictionary.
    print_words(wordMap); //Print dictionary words.

    return 0;
}
