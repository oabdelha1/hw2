#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include <queue>
#include <map>

class MyDataStore : public DataStore {

public:

    ~MyDataStore();

    void addProduct(Product *p);

    void addUser(User *u);

    std::vector<Product *> search(std::vector<std::string> &terms, int type);

    void dump(std::ostream &ofile);

    void addCart(std::string name, Product *p);

    void viewCart(std::string name);

protected:

    std::map<std::string, std::queue<Product*> > carts;
    std::vector<Product*> prods_;
    std::vector<User*> users_;

};
#endif
