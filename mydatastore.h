#ifndef MDATASTORE_H
#define MDATASTORE_H
#include "datastore.h"
#include "util.h"
#include "product.h"
#include <string>
#include <queue>
#include <map>

class MyDataStore : public DataStore {
public:
    MyDataStore() {}
    ~MyDataStore() {
        for (Product* prod : products_) {
            delete prod;
        }
        for (std::pair<std::string, User*> toDelete : mapBuyer_) {
            delete toDelete.second;
        }
    }

    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void addToCart(std::string username, Product* toAdd);
    void viewCart(std::string username);
    void buyCart(std::string username);
    void dump(std::ostream& ofile);

private:
    std::map<std::string, User*> mapBuyer_;
    std::set<Product*> products_;

    std::map<std::string, std::set<Product*>> productMap; 

    std::map<User*, std::deque<Product*> > shoppingCart_;


};

#endif