#include <sstream>
#include <iomanip>
#include "clothing.h"

using namespace std;

Clothing::Clothing(const string& category, const string& name, double price, int qty,
const string& brand, const string& size) :
Product("clothing", name, price, qty)
{
brand_ = brand;
size_ = size;
}

Clothing::~Clothing() = default;

string Clothing::getBrand() const
{
return brand_;
}

string Clothing::getSize() const
{
return size_;
}

set<string> Clothing::keywords() const
{
set<string> clothingKeywords;
string currWord;

// adds the name keywords
for (char c : name_) {
    if (ispunct(c) && currWord.size() > 1 || 
        isspace(c) && currWord.size() > 1) {
        clothingKeywords.emplace(currWord);
        currWord = "";
    }  
    else if (ispunct(c) || isspace(c)) {
        currWord = "";
    }
    else {
        currWord += tolower(c);
    }
}

// check if there's any leftover string that needs to be added
if (currWord.size() > 1) {
    clothingKeywords.emplace(currWord);
    currWord = "";
}

// adds the brand keywords
for (char c : brand_) {
    if (ispunct(c) && currWord.size() > 1 || 
        isspace(c) && currWord.size() > 1) {
        clothingKeywords.emplace(currWord);
        currWord = "";
    }  
    else if (ispunct(c) || isspace(c)) {
        currWord = "";
    }
    else {
        currWord += tolower(c);
    }
}

// check if there's any leftover string that needs to be added
if (currWord.size() > 1) {
    clothingKeywords.emplace(currWord);
    currWord = "";
}

return clothingKeywords;

}

bool Clothing::isMatch(vector<string>& searchTerms) const
{
return false;
}

string Clothing::displayString() const
{
ostringstream outputString;

int priceDecimalPointIndex = 0;
string priceStr = to_string(price_);

for (size_t i = 0; i < priceStr.size(); ++i) {
    if (priceStr[i] == '.') {
        priceDecimalPointIndex = i;
        break;
    } 
}

outputString << name_ << endl;
outputString << "Size: " << size_ << " Brand: " << brand_ << endl;
outputString << priceStr.substr(0, priceDecimalPointIndex) 
             << priceStr.substr(priceDecimalPointIndex, 3) << ' '