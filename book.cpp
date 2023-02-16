#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include "product.h"
#include "book.h"

Book::Book(const std::string category, const std::string name, double price, int qty, 
           const std::string isbn, const std::string author) : 
    Product (category, name, price, qty)
{
    isbn_ = isbn;
    author_ = author;

}

Book::~Book(){

}

std::set<std::string> Book::keywords() const {


    std::string tempname = convToLower(name_);
    std::string tempisbn = convToLower(isbn_);
    std::string tempauth = convToLower(author_);

    convToLower(tempname);
    convToLower(tempauth);

    std::set<std::string> retwords = parseStringToWords(tempname);

    retwords.insert(tempisbn);
    retwords.insert(tempauth);

    return retwords;
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const{
    return false;
}

std::string Book::displayString() const {
    std::string ret;         //= name_;

    std::stringstream ss;
    ss << name_ << '\n';
    ss << "Author: " << author_ << " ISBN: " << isbn_ << '\n';
    ss <<std::fixed<< std::setprecision(2) << price_ << " " << qty_ << " left.";
    ret = ss.str();

    return ret;
}

void Book::dump(std::ostream& os) const {
    os << "Dump Test" << std::endl;
}