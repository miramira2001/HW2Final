#include <sstream>
#include <iomanip>
#include "book.h"
#include <ctype.h>

using namespace std;

Book::Book(const string& category, const string& name, double price, int qty,
    const string& isbn, const string& author) : 
        Product("book", name, price, qty)
{
    isbn_ = isbn;
    author_ = author;
}

string Book::getAuthor() const
{
    return author_;
}

string Book::getISBN() const
{
    return isbn_;
}

set<string> Book::keywords() const 
{
    set<string> bookWords = { isbn_ };
    string currWord;

    for (size_t i = 0; i < name_.size(); ++i) {
        if ((ispunct(name_[i]) && currWord.size() > 1) || 
        (isspace(name_[i]) && currWord.size() > 1)) {
            bookWords.insert(currWord);
            currWord.clear();
        }  
        else if (ispunct(name_[i]) || isspace(name_[i])) {
            currWord.clear();
        }
        else {
            currWord += tolower(name_[i]);
        }
    }

    // check if there's any leftover string that needs to be added
    if (currWord.size() > 1) {
        bookWords.insert(currWord);
        currWord.clear();
    }

    for (size_t i = 0; i < author_.size(); ++i) {
        if ((ispunct(author_[i]) && currWord.size() > 1) || 
            (isspace(author_[i]) && currWord.size() > 1)) {
            bookWords.insert(currWord);
            currWord.clear();
        }  
        else if (ispunct(author_[i]) || isspace(author_[i])) {
            currWord.clear();
        }
        else {
            currWord += tolower(author_[i]);
        }
    }

    // check if there's any leftover string that needs to be added
    if (currWord.size() > 1) {
        bookWords.insert(currWord);
        currWord.clear();
    }

    return bookWords;
}

bool Book::isMatch(const vector<string>& searchTerms) const
{
    return false;
}

string Book::displayString() const {
    string outputString;

    int priceDecimalPointIndex = 0;
    string priceStr = to_string(price_);

    for (size_t i = 0; i < priceStr.size(); ++i) {
        if (priceStr[i] == '.') {
            priceDecimalPointIndex = i;
            break;
        } 
    }

    outputString += name_;
    outputString += '\n';
    outputString += "Author: ";
    outputString += author_;
    outputString += " ISBN: "