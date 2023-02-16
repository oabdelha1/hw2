#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
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


    std::string tempname = convToLower(name_);
    std::string tempbrand = convToLower(brand_);
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
    std::string ret;

    std::stringstream ss;
    ss << name_ << '\n';
    ss << "Size: " << size_ << " Brand: " << brand_ << '\n';
    ss <<std::fixed<< std::setprecision(2) << price_ << " " << qty_ << " left.";
    ret = ss.str();

    return ret;
}

void Clothing::dump(std::ostream& os) const {
    os << "Dump Test" << std::endl;
}