#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Movie : public Product
{
public:
Movie(const std::string& category, const std::string& name, double price, int qty, const std::string& genre, const std::string& rating);
virtual ~Movie();

std::string getGenre() const;
std::string getRating() const;

virtual std::set<std::string> keywords() const override;
virtual bool isMatch(const std::vector<std::string>& searchTerms) const override;
virtual std::string displayString() const override;
virtual void dump(std::ostream& os) const override;

private:
std::string genre_;
std::string rating_;
};