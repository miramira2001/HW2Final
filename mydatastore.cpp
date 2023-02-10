#include "mydatastore.h"

void MyDataStore::addProduct(Product* p) {
    products_.insert(p);

    for (const auto& keyword : p->keywords()) {
if (productMap.count(keyword)) {
productMap[keyword].insert(p);
} else {
std::set<Product*> newProductSet;
newProductSet.insert(p);
productMap.emplace(keyword, newProductSet);
}
}
}

void MyDataStore::addUser(User* u) {
    mapBuyer_.emplace(u->getName(), u);

std::deque<Product*> emptyCart;
shoppingCart_.emplace(u, emptyCart);
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {


    std::vector<Product*> matches;
    std::set<Product*> intermediary;
for (const auto& term : terms) {
    auto var = productMap.find(term);
    if (var == productMap.end()) {
        continue;
    }

    if (type) {
        intermediary = setUnion(intermediary, var->second);
    } else {
        if (intermediary.empty()) {
            intermediary = var->second;
        } else {
            intermediary = setIntersection(intermediary, var->second);
        }
    }
}

    for (Product* itr1: intermediary) {
        matches.push_back(itr1);
    }

    return matches;
}
void MyDataStore::dump(std::ostream& ofile) {
    ofile << "<products>\n";
    for (Product* outputProduct: products_) {
        outputProduct->dump(ofile);
    }
    ofile << "</products>\n";
    ofile << "<users>\n";
    for (std::pair<std::string, User*> outputUser: mapBuyer_) {
        outputUser.second->dump(ofile);
    }
    ofile << "</users>\n";
}

void MyDataStore::addToCart(std::string username, Product* toAdd) {
    if (mapBuyer_.find(username) == mapBuyer_.end()) {
        std::cout << "Invalid request" << std::endl;
        return;
    }
    shoppingCart_.at(mapBuyer_.at(username)).push_back(toAdd);
}

void MyDataStore::buyCart(std::string username) {
   
    if (mapBuyer_.find(username) == mapBuyer_.end()) {
        std::cout << "Invalid username" << std::endl;
        return;
    }

    std::deque<Product*> fill;
    for (Product* userShop: shoppingCart_.at(mapBuyer_.at(username))) {
        if (userShop->getQty() == 0) {
fill.push_back(userShop);
        } else if (mapBuyer_.at(username)->getBalance() < userShop->getPrice()) {
            fill.push_back(userShop);
        } else {
            mapBuyer_.at(username)->deductAmount(userShop->getPrice());
            userShop->subtractQty(1);
        }
    }

    shoppingCart_.at(mapBuyer_.at(username)) = fill;
}

void MyDataStore::viewCart(std::string username) {
    if (mapBuyer_.find(username) == mapBuyer_.end()) {
        std::cout << "Invalid username" << std::endl;
        return;
    }
    std::deque<Product*>::iterator var = shoppingCart_.at(mapBuyer_.at(username)).begin();

    int IndValue = 0;

    while (var != shoppingCart_.at(mapBuyer_.at(username)).end()) {
        std::cout << "Item " << IndValue + 1 << std::endl;
        std::cout << (*var)->displayString();
        std::cout << std::endl;
        IndValue = IndValue + 1;
        var = var + 1;
    }
    
}



