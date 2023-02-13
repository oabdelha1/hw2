#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "clothing.h"

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, 
           const std::string size, const std::string brand) : 
    Product (category, name, price, qty)
{
    brand_ = brand;
    size_ = size;

}

Clothing::~Clothing(){

}

std::set<std::string> Clothing::keywords() const {


    std::string tempname = name_;
    std::string tempbrand = brand_;
    //std::string tempsize = size_;

    convToLower(tempname);
    convToLower(tempbrand);

    std::set<std::string> retwords = parseStringToWords(tempname);

    retwords.insert(tempbrand);
    //retwords.insert(tempsize);

    return retwords;
}

bool Clothing::isMatch(std::vector<std::string>& searchTerms) const{
    return false;
}

std::string Clothing::displayString() const {
    return "Display String test";
}

void Clothing::dump(std::ostream& os) const {
    os << "Dump Test" << std::endl;
}