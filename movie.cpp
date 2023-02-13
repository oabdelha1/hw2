#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "movie.h"
#include "util.h"

Movie::Movie(const std::string category, const std::string name, double price, int qty, 
           const std::string genre, const std::string rating) : 
    Product (category, name, price, qty)
{
    genre_ = genre;
    rating_ = rating;

}

Movie::~Movie(){

}

std::set<std::string> Movie::keywords() const {


    std::string tempname = name_;
    std::string tempgenre = genre_;
    //Change to rating? std::string tempauth = author_;

    convToLower(tempname);
    convToLower(tempgenre);

    std::set<std::string> retwords = parseStringToWords(tempname);

    retwords.insert(tempname);
    retwords.insert(tempgenre);

    return retwords;
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const{
    return false;
}

std::string Movie::displayString() const {
    return "Display String test";
}

void Movie::dump(std::ostream& os) const {
    os << "Dump Test" << std::endl;
}