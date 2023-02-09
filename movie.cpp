#include <sstream>
#include <iomanip>
#include "movie.h"
#include <ctype.h>

using namespace std;

Movie::Movie(const std::string &category, const std::string &name, double price, int qty,
const std::string &genre, const std::string &rating) :
Product("movie", name, price, qty)
{
rating_ = rating;
genre_ = genre;
}

Movie::~Movie() = default;

std::string Movie::getGenre() const
{
return genre_;
}

std::string Movie::getRating() const
{
return rating_;
}

std::setstd::string Movie::keywords() const
{
std::setstd::string movieWords;

std::string currWord;

// make the genre and rating lowercase
for (char c : rating_)
{
    currWord += std::tolower(c);
}
movieWords.insert(currWord);
currWord.clear();

for (char c : genre_)
{
    currWord += std::tolower(c);
}
movieWords.insert(currWord);
currWord.clear();

for (char c : name_)
{
    if ((std::ispunct(c) && (currWord.size() > 1)) || 
        (std::isspace(c) && (currWord.size() > 1)))
    {
        movieWords.insert(currWord);
        currWord.clear();
    }  
    else if (std::ispunct(c) || std::isspace(c))
    {
        currWord.clear();
    }
    else
    {
        currWord += std::tolower(c);
    }
}

// check if there's any leftover string that needs to be added
if (currWord.size() > 1)
{
    movieWords.insert(currWord);
    currWord.clear();
}

return movieWords;

}

bool Movie::isMatch(std::vectorstd::string &searchTerms) const
{
for (const auto &searchTerm : searchTerms)
{
auto iter = std::find_if(keywords().begin(), keywords().end(),
[&searchTerm](const auto &keyword)
{
return keyword == searchTerm;
});
if (iter != keywords().end())
{
return true;
}
}
return false;
}

std::string Movie::displayString() const
{
std::ostringstream outputString;
outputString << std::fixed << std::setprecision(2);

int priceDecimalPointIndex = 0;
std::string priceStr = std::to_string(price_);

for (std::size_t i = 0; i < priceStr.size(); ++i)
{
    if (priceStr[i] == '.')
    {
        priceDecimalPointIndex = i;
        break;
    } 