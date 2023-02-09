#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include <ctype.h>

using namespace std;

std::string toLower(const std::string &src)
{
    std::string dest = src;
    std::transform(dest.begin(), dest.end(), dest.begin(), ::tolower);
    return dest;
}

std::set<std::string> parseWords(const std::string &rawWords)
{
    std::set<std::string> words;
    std::string currWord;
    std::string trimmedRawWords = trim(rawWords);

    for (char c : trimmedRawWords) {
        if (ispunct(c)) {
            if (currWord.size() > 1) {
                words.insert(toLower(currWord));
                currWord.clear();
            }
        } else if (isspace(c)) {
            if (currWord.size() > 1) {
                words.insert(toLower(currWord));
                currWord.clear();
            }
        } else {
            currWord += c;
        }
    }

    if (!currWord.empty() && currWord.size() > 1) {
        words.insert(toLower(currWord));
    }

    return words;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}