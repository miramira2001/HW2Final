#ifndef MDATASTORE_H
#define MDATASTORE_H
#include "datastore.h"
#include "util.h"
#include "product.h"
#include <map>
#include <string>
#include <queue>

class MyDataStore : public DataStore {
public:
    MyDataStore() = default;

    ~MyDataStore() {
        for (Product* prod : products_) {
            delete prod;
        }
        for (auto [username, user] : users_map_) {
            delete user;
        }
    }

    void addProduct(Product* p) override;

    void addUser(User* u) override;

    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;

    void addToCart(std::string username, Product* toAdd) override;

    void viewCart(std::string username) override;

    void buyCart(std::string username) override;

    void dump(std::ostream& ofile) override;

private:
    std::map<std::string, User*> users_map_;
    std::set<Product*> products_;

    std::map<std::string, std::set<Product*>> keyword_mapping; 

    std::map<User*, std::deque<Product*>> cart_;
};

#endif