#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Book : public Product {
public:
Book(const std::string& category, const std::string& name, double price,
int qty, const std::string& isbn, const std::string& author);
virtual ~Book();

virtual std::set<std::string> keywords() const override;

virtual bool isMatch(const std::vector<std::string>& searchTerms) const override;

virtual std::string displayString() const override;

virtual void dump(std::ostream& os) const override;

// New accessors and mutators
std::string getISBN() const;
std::string getAuthor() const;

private:
std::string isbn_;
std::string author_;
};