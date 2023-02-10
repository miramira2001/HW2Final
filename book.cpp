#include <sstream>
#include <iomanip>
#include "book.h"
#include <ctype.h>

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty,
    const std::string isbn, const std::string author) : 
Product("book", name, price, qty), isbn_(isbn), author_(author) {

}

Book::~Book()
{
}

std::string Book::grabUserisbn() const
{
    return isbn_;
}

std::string Book::grabUserAuthor() const
{
    return author_;
}

std::set<std::string> Book::keywords() const 
{
    std::set<std::string> wordsOfBook;
    wordsOfBook.insert(isbn_);

    std::string CurrentW;
    unsigned long i = 0;
while (i < name_.size()) {
    if ((isspace(name_[i]) && (CurrentW.size() > 1)) || 
        (ispunct(name_[i]) && (CurrentW.size() > 1))) {
        wordsOfBook.insert(CurrentW);
        CurrentW.clear();
    }  
    else if (ispunct(name_[i]) || isspace(name_[i])) {
        CurrentW.clear();
    }
    else {
        CurrentW += tolower(name_[i]);
    }
    ++i;
}

    if (CurrentW.size() > 1) {
        wordsOfBook.insert(CurrentW);
        CurrentW = "";
    }

    for (unsigned long i = 0; i < author_.size(); ++i) {
        if ((ispunct(author_[i]) && (CurrentW.size() > 1)) || 
            (isspace(author_[i]) && (CurrentW.size() > 1))) {
            wordsOfBook.insert(CurrentW);
            CurrentW = "";
        }  
        else if (ispunct(author_[i]) || isspace(author_[i])) {
            CurrentW = "";
        }
        else {
            CurrentW += tolower(author_[i]);
        }
    }

    if (CurrentW.size() > 1) {
        wordsOfBook.insert(CurrentW);
        CurrentW = "";
    }

    return wordsOfBook;
}

bool Book::CorrectItem(std::vector<std::string>& searchTerms) const
{
    return false;
}

std::string Book::displayString() const {
    std::string display;

    int LowerPoint = 0;
    string StringOrPrice = to_string(price_);

    for (const auto& element : StringOrPrice) {
    if (element == '.') {
        LowerPoint = &element - &StringOrPrice[0];
    }
}
    display += name_;
    display += "\n";
    display += "Author: " + author_ + " ISBN: " + isbn_;
    display += "\n";
    display += StringOrPrice.substr(0, LowerPoint);
    display += StringOrPrice.substr(LowerPoint, 3);
    display += ' ';
    display += to_string(qty_);
    display += " left.";

    return display;
}

void Book::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << endl;
    os << isbn_ << "\n" << author_ << endl;
}