#include <sstream>
#include <iomanip>
#include "clothing.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty,
    const std::string brand, const std::string size) :
    Product("clothing", name, price, qty)
{
    brand_ = brand;
    size_  = size;
} 

Clothing::~Clothing()
{
}

std::string Clothing::grabUserBrand() const
{
    return brand_;
}

std::string Clothing::grabUserSize() const
{
    return size_;
}

std::set<std::string> Clothing::keywords() const
{
    std::set<std::string> wordsOfClothes;
    std::string CurrentW;
    unsigned long i = 0;
while (i < name_.size()) {
if ((ispunct(name_[i]) && (CurrentW.size() > 1)) || (isspace(name_[i]) && (CurrentW.size() > 1))) {
wordsOfClothes.insert(CurrentW);
CurrentW = "";
}
else if (ispunct(name_[i]) || isspace(name_[i])) {
CurrentW = "";
}
else {
CurrentW += tolower(name_[i]);
}
i++;
}

    if (CurrentW.size() > 1) {
        wordsOfClothes.insert(CurrentW);
        CurrentW = "";
    }

    for (unsigned long i = 0; i < brand_.size(); ++i) {
        if ((ispunct(brand_[i]) && (CurrentW.size() > 1)) || 
            (isspace(brand_[i]) && (CurrentW.size() > 1))) {
            wordsOfClothes.insert(CurrentW);
            CurrentW = "";
        }  
        else if (ispunct(brand_[i]) || isspace(brand_[i])) {
            CurrentW = "";
        }
        else {
            CurrentW += tolower(brand_[i]);
        }
    }

    if (CurrentW.size() > 1) {
        wordsOfClothes.insert(CurrentW);
        CurrentW = "";
    }

    return wordsOfClothes;

}

bool Clothing::CorrectItem(std::vector<std::string>& searchTerms) const
{
   return false;
}

std::string Clothing::displayString() const
{
    std::string display;

    int LowerPoint = 0;
    string priceStr = to_string(price_);

    for (unsigned long i = 0; i < priceStr.size(); ++i) {
if (priceStr[i] == '.') {
LowerPoint = i;
}
}


 display += name_;
    display += "\n";
    display += "Size: " + size_ + " Brand: " + brand_;
    display += "\n";
    display += priceStr.substr(0, LowerPoint);
    display += priceStr.substr(LowerPoint, 3);
    display += ' ';
    display += to_string(qty_);
    display += " left.";

    return display;
}

void Clothing::dump(std::ostream& os) const
{
    os << std::fixed;
    os << std::setprecision(2);
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << endl;
    os << size_ << "\n" << brand_ << endl;
}