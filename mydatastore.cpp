#include "mydatastore.h"

void MyDataStore::addProduct(Product* p) {
    products_.insert(p);

    // Add the product to the corresponding set in keywordMapping
    for (const auto& keyword : p->keywords()) {
        auto it = keywordMapping.find(keyword);
        if (it != keywordMapping.end()) {
            it->second.insert(p);
        } else {
            std::set<Product*> new_set;
            new_set.insert(p);
            keywordMapping[keyword] = new_set;
        }
    }
}

void MyDataStore::addUser(User* u) {
    // Add the user to the mapping of usernames to user objects
    users_map_[u->getName()] = u;

    // Initialize a deque for the new user's cart
    std::deque<Product*> new_cart;
    cart_[u] = new_cart;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
    // type 0 is AND
    // type 1 is OR

    std::vector<Product*> matches;
    std::set<Product*> intermediary;

    if (type) {
        // Perform an OR search
        for (const auto& term : terms) {
            auto it = keywordMapping.find(term);
            if (it != keywordMapping.end()) {
                intermediary = setUnion(intermediary, it->second);
            }
        }
    } else {
        // Perform an AND search
        for (const auto& term : terms) {
            auto it = keywordMapping.find(term);
            if (it != keywordMapping.end()) {
                /* If this is the first keyword, we need to initialize the intermediary
                set, otherwise we keep finding the intersection of more and more sets */
                if (intermediary.empty()) {
                    intermediary = it->second;
                } else {
                    intermediary = setIntersection(intermediary, it->second);
                }
            }
        }
    }

    // Copy the intermediary set to the matches vector
    for (const auto& product : intermediary) {
        matches.push_back(product);
    }

    return matches;
}

void MyDataStore::addToCart(std::string username, Product*