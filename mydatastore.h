#ifndef USER_H
#define USER_H

#include <vector>
#include <set>
#include <map>
#include <iostream>

#include "util.h"
#include "user.h"
#include "product.h"

class MyDataStore {
public:
    MyDataStore() { }
    ~MyDataStore() {
        for (auto p = products) delete p;
        for (auto u = users) delete u;
    }

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

    /**
     *
     */
    bool addToCart(const std::string& user, const std::vector<Product*>& product,  const unsigned int& index);

    /**
     *
     */
    void viewCart(const std::string& user);

    /**
     *
     */
    bool buyCart(const std::string& user);

protected:
    // vector of all users
    std::vector<User*> users;
    //vector for all products
    std::vector<Product*> products;
    // map of keywords to products
    std::map<std::string, std::set<Product*>> keywords;
    // map of user to cart
    std::map<std::string, std::vector<Product*>> carts;
}


#endif