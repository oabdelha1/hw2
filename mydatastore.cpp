//
// Created by Omar Abd-Elhamid on 2/14/23.
//
#include <string>
//#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "mydatastore.h"
#include <queue>
#include <map>
#include "util.h"

MyDataStore::~MyDataStore() {

    for (size_t i = 0; i < users_.size(); i++){
        delete users_[i];
    }
    for (size_t i = 0; i < prods_.size(); i++){
        delete prods_[i];
    }

}

void MyDataStore::addCart(std::string name, Product *p) {


    bool found = false;
    for (size_t i = 0; i < users_.size(); i++){
        if (users_[i]->getName() == name){
            found = true;
            std::cout << "Found " << name << std::endl;
        }
    }

    if (found == false){
        std::cout << "User not found" << std::endl;
    }
    else{
        carts[name].push_back(p);
        std::cout << "Just added " << p->getName() << " for " << name << std::endl;
    }

    /*
    std::map<std::string, std::vector<Product*> >::iterator it;
    it = carts.find(name);
    if(it != carts.end()){
        it->second.push_back(p);
    }
    else{
        std::cout << "User Not Found" << std::endl;
    }
     */
}

void MyDataStore::addProduct(Product *p) {
    prods_.push_back(p);
    std::set<std::string> keycopy = p->keywords();

    std::set<std::string>::iterator it;
    for (it = keycopy.begin(); it != keycopy.end(); it++){
        keywords_[*it].insert(p);
        std::cout <<"Testing: just added " << *it << " to keyword map" << std::endl;
    }

}

void MyDataStore::addUser(User *u) {

    users_.push_back(u);
    carts[u->getName()];


}

void MyDataStore::dump(std::ostream &ofile) {

    ofile << "<products>" << std::endl;
    for (size_t i = 0; i < prods_.size(); i++){
        prods_[i]->dump(ofile);
    }
    ofile << "</products>" << std::endl;

    ofile << "<users>" << std::endl;
    for (size_t i = 0; i < users_.size(); i++){
        users_[i]->dump(ofile);
    }
    ofile << "</users>" << std::endl;

}

std::vector<Product *> MyDataStore::search(std::vector<std::string> &terms, int type) {
    //Final Output Vector
    std::vector<Product* > output;

    //Only 1 term case, error as placeholder
    if (terms.size() == 1){

        std::map<std::string, std::set<Product*> >::iterator itsing;
        itsing = keywords_.find(terms[0]);
        if(itsing == keywords_.end() ){
            return output;
        }
        std::set<Product*> termsing;
        termsing = itsing->second;

        std::set<Product*>::iterator finalsingiterator;
        for (finalsingiterator = termsing.begin(); finalsingiterator!= termsing.end(); finalsingiterator++){
            output.push_back(*finalsingiterator);
        }

        return output;

    }

    //Terms
    std::string term1 = convToLower(terms[0]);
    std::string term2 = convToLower(terms[1]);

    //std::cout << "Created search terms: " << term1 << term2 << std::endl;

    //Sets for individual terms and combined
    std::set<Product*> term1prods;
    std::set<Product*> term2prods;
    std::set<Product*> totalterm;

    //Check if there are the keywords
    /*
    std::map<std::string, std::set<Product*> >::iterator checker;
    for (checker = keywords_.begin(); checker != keywords_.end(); checker ++){
        //std::cout << checker->first << ", " << std::endl;
    }
    std::cout << std::endl;
    */
    //Placeholder for missing word


    if(keywords_.find(term1) == keywords_.end() || keywords_.find(term2) == keywords_.end()){
        //std::cout << "Failed to find term" << std::endl;
        return output;
    }

    //Try Again:



    //Copy the sets
    term1prods = keywords_[term1];
    term2prods = keywords_[term2];

    //Test each set
    /*
    std::set<Product*>::iterator checkterm1;
    std::set<Product*>::iterator checkterm2;
    for (checkterm1 = term1prods.begin(); checkterm1!= term1prods.end(); checkterm1++){
        std::cout << "Product: " << (*checkterm1)->getName() << std::endl;
    }
     */

    //Create the final set
    if(type == 0){
        //std::cout << "Type 0" << std::endl;
        totalterm = setUnion<Product*>(term1prods, term2prods);
    }
    if(type == 1){
        //std::cout << "Type 1" << std::endl;
        totalterm = setIntersection<Product*>(term1prods, term2prods);
    }

    //Test the total set
    /*
    std::set<Product*>::iterator checkfinal;
    for (checkfinal = totalterm.begin(); checkfinal!= totalterm.end(); checkfinal ++){
        std::cout << "Product: " << (*checkfinal)->getName() << std::endl;
    }
    */

    //Add from final set to vector
    std::set<Product*>::iterator itfin;
    for (itfin = totalterm.begin(); itfin != totalterm.end(); itfin++){
        output.push_back(*itfin);
    }

    return output;


    /*
    std::map<std::string, std::set<Product*> >::iterator it1;
    std::map<std::string, std::set<Product*> >::iterator it2;

    //DO this if there's only one term
    if (terms.size() < 2){

        //Check if the terms exist
        std::map<std::string, std::set<Product*> >::iterator itsingle;
        itsingle = keywords_.find(terms[0]);
        if (itsingle != keywords_.end()){
            std::set<Product*>::iterator itprodsing;

        }

    }

    it1 = keywords_.find(terms[0]);
    it2 = keywords_.find(terms[1]);

    for (int i = 0; i < terms.size(); i++){
        terms[i] = convToLower(terms[i]);
    }

    if ((it1 != keywords_.end()) && (it2 != keywords_.end())){

    }
     */
}

std::vector<Product*> MyDataStore::viewCart(std::string name) {
    std::vector<Product*> output;

    std::map<std::string, std::vector<Product*> >::iterator it;
    it = carts.find(name);
    if(it != carts.end()){
        //std::cout << "Test seeing in the Cart for " << name << std::endl;
        return it->second;
    }
    return output;
}