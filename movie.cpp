#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
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


    std::string tempname = convToLower(name_);
    std::string tempgenre = convToLower(genre_);
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
    std::string ret;

    std::stringstream ss;
    ss << name_ << '\n';
    ss << "Genre: " << genre_ << " Rating: " << rating_ << '\n';
    ss <<std::fixed<< std::setprecision(2) << price_ << " " << qty_ << " left.";
    ret = ss.str();

    return ret;
}

void Movie::dump(std::ostream& os) const {
    os << "Dump Test" << std::endl;
}