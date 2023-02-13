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
    Clothing(const std::string category, const std::string name, double price, int qty, const std::string brand, const std::string size);
    virtual ~Clothing();

    std::set<std::string> keywords() const;
    bool isMatch(std::vector<std::string>& searchTerms) const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

private:
    std::string brand_;
    std::string size_;
};

#endif