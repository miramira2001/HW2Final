#include <sstream>
#include <iomanip>
#include "movie.h"
#include <ctype.h>

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty,
    const std::string genre, const std::string rating) :
    Product("movie", name, price, qty)
{
    rating_ = rating;
    genre_ = genre;
} 

Movie::~Movie()
{
}

std::string Movie::grabUserGenre() const
{
    return genre_;
}

std::string Movie::grabUserRating() const
{
    return rating_;
}

std::set<std::string> Movie::keywords() const
{
    std::set<std::string> wordsOfMovie;

    std::string CurrentW;

    unsigned i = 0;

while (i < rating_.size()) {
    CurrentW += tolower(rating_[i]);
    ++i;
}
wordsOfMovie.insert(CurrentW);
CurrentW.clear();

i = 0;
while (i < genre_.size()) {
    CurrentW += tolower(genre_[i]);
    ++i;
}
wordsOfMovie.insert(CurrentW);
CurrentW.clear();

    for (unsigned i = 0; i < name_.size(); ++i) {
        if ((ispunct(name_[i]) && (CurrentW.size() > 1)) || 
            (isspace(name_[i]) && (CurrentW.size() > 1))) {
            wordsOfMovie.insert(CurrentW);
            CurrentW = "";
        }  
        else if (ispunct(name_[i]) || isspace(name_[i])) {
            CurrentW = "";
        }
        else {
            CurrentW += tolower(name_[i]);
        }
    }

    if (CurrentW.size() > 1) {
        wordsOfMovie.insert(CurrentW);
        CurrentW = "";
    }
    
    return wordsOfMovie;

}

bool Movie::CorrectItem(std::vector<std::string>& searchTerms) const
{
    return false;
}

std::string Movie::displayString() const
{
    std::string display;

    int LowerPoint = 0;
    string priceStr = to_string(price_);

    for (size_t i = 0; i < priceStr.size(); ++i) {
    if (priceStr[i] == '.') {
        LowerPoint = i;
    } 
}

    display += name_;
    display += "\n";
    display += "Genre: " + genre_ + " Rating: " + rating_;
    display += "\n";
    display += priceStr.substr(0, LowerPoint);
    display += priceStr.substr(LowerPoint, 3);
    display += ' ';
    display += to_string(qty_);
    display += " left.";

    return display;
}

void Movie::dump(std::ostream& os) const
{
    os << std::fixed;
    os << std::setprecision(2);
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << endl;
    os << genre_ << "\n" << rating_ << endl;
}