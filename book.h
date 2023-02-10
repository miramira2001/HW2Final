#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include "product.h"

class Book : public Product 
{
public:
    Book(const std::string category, const std::string name, double price,
    int qty, const std::string author, const std::string isbn);
    virtual ~Book();
    virtual std::set<std::string> keywords() const;
    virtual void dump(std::ostream& os) const;
    virtual std::string displayString() const;
    virtual bool CorrectItem(std::vector<std::string>& searchTerms) const;


    std::string grabUserisbn() const;
    std::string grabUserAuthor() const;

private:
    std::string isbn_;
    std::string author_;
};
#endif