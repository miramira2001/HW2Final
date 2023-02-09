#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Clothing : public Product {
public:
    Clothing(std::string category, std::string name, double price, int qty, std::string size, std::string brand);
    ~Clothing() = default;

    std::set<std::string> keywords() const override;
    bool isMatch(std::vector<std::string>& searchTerms) const override;
    std::string displayString() const override;
    void dump(std::ostream& os) const override;

    std::string getBrand() const;
    std::string getSize() const;

private:
    std::string brand_;
    std::string size_;
};