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

MyDataStore::~MyDataStore() {

    for (int i = 0; i < users_.size(); i++){
        delete users_[i];
    }
    for (int i = 0; i < prods_.size(); i++){
        delete prods_[i];
    }

}

void MyDataStore::addCart(std::string name, Product *p) {
    std::map<std::string, std::queue<Product*> >::iterator it;
    it = carts.find(name);
    if(it != carts.end()){
        it->second.push(p);
    }
    else{
        std::cout << "User Not Found" << std::endl;
    }
}

void MyDataStore::addProduct(Product *p) {
    prods_.push_back(p);
}

void MyDataStore::addUser(User *u) {
    users_.push_back(u);
}

void MyDataStore::dump(std::ostream &ofile) {
    ofile << "just test" << std::endl;
}

std::vector<Product *> MyDataStore::search(std::vector<std::string> &terms, int type) {

}

void MyDataStore::viewCart(std::string name) {
    std::map<std::string, std::queue<Product*> >::iterator it;
    it = carts.find(name);
    if(it != carts.end()){
        std::cout << "Test seeing in the Cart for " << name << std::endl;
    }
}