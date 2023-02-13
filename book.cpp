#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
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


    std::string tempname = name_;
    std::string tempisbn = isbn_;
    std::string tempauth = author_;

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
    return "Display String test";
}

void Book::dump(std::ostream& os) const {
    os << "Dump Test" << std::endl;
}