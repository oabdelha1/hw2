#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "book.h"

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn) : 
    Product (category, name, price, qty)
{
    isbn_ = isbn;
    author_ = author;

}

Book::~Book(){

}

std::set<std::string> Book::keywords() const {

}

bool Book::isMatch(std::vector<std::string>& searchTerms) const{

}

std::string Book::displayString() const {

}

void Book::dump(std::ostream& os) const {

}