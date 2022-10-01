#include "mydatastore.h"

/**
 * Adds a product to the data store
 */
void MyDataStore::addProduct(Product* p) { products.push_back(p); }

/**
 * Adds a user to the data store
 */
void MyDataStore::addUser(User* u) { users.push_back(u); }

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 */
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
    // temporary set of products to later transfer to the returnVector
    std::set<Product*> searchProducts;

    // iterate through terms
    for (std::vector<std::string>::iterator curr = terms.begin();
        curr != terms.end();
        ++curr) {
        auto index = keywords.find(*curr);
        if (searchProducts.empty()) searchProducts = index->second;

        // AND SEARCH
        if (type == 0) setIntersection(searchProducts, index->second);
        // OR SEARCH
        else if (type == 1) setUnion(searchProducts, index->second);
    }

    // copy set to vector
    std::vector<Product*> returnVector;
    for (td::set<Product*>::iterator it = searchProducts.begin();
        it != searchProducts.end();
        ++it) returnVector.push_back(it);

    // return vector
    return returnVector;
}

/**
 * Reproduce the database file from the current Products and User values
 */
void MyDataStore::dump(std::ostream& ofile) {
    ofile << "<products>\n";
    for (std::vector<Product*>::iterator it = products.begin();
        it != products.end();
        ++it) {
        (*it)->dump(ofile);
    }
    ofile << "</products>\n";

    ofile << "<users>\n";
    for (std::vector<User*>::iterator it = users.begin();
         it != users.end();
         ++it) {
        (*it)->dump(ofile);
    }
    ofile << "</users>\n";
}

/**
 * Add a product to the given user's cart
 */
bool MyDataStore::addToCart(const std::string& user, const std::vector<Product*>& product,  const unsigned int& index) {
    // if you cannot find the user in carts or the product index is greater than the amount of products offered -> return
    if (carts.find(user) == carts.end()) {
        if (users.find(user) == users.end()) return false;
        std::vector<Product*> temp;
        temp.push_back(product[index-1]);
        carts.insert(std::pair<user, temp>);
        return true;
    }

    if (index > product.size()) return false;

    // create iterator pointing towards the user then
    std::map<std::string, std::vector<Product*>>::iterator it = carts.find(user);
    // add item to the user's cart
    it->second.push_back(product[index-1]);
    return true;
}

/**
 * Print out user's cart
 */
void MyDataStore::viewCart(const std::string& user) {
    // check if user exists
    if (carts.find(user) == user.end()) {
        std::cout << "No Cart - " << std::endl;
        return;
    }

    std::map<std::string, std::vector<Product*>>::iterator cart = carts.find(user);
    // check if user's cart is empty
    if (cart->second.empty()) {
        std::cout << user << "'s Cart Empty - " << std::endl;
        return;
    }

    // print out user's cart
    std::cout << user << "'s Cart - " << std::endl;
    for (std::vector<Product*>::iterator it = cart->second.begin();
        it != cart->second.end();
        ++it) {
        std::cout << (*it)->getName() << " - " << (*it)->getPrice() << std::endl;
    }
}

/**
 * Buy products in given user's cart
 */
bool MyDataStore::buyCart(const std::string& user) {
    // check if user exists
    if (carts.find(user) == user.end()) {
        std::cout << "No Cart - " << std::endl;
        return;
    }

    std::map<std::string, std::vector<Product*>>::iterator cart = carts.find(user);
    // find user balance
    for (std::vector<User*>::iterator u = users.begin();
        u != users.end();
        ++u) {
        if ((*u)->getName() == user) break;
    }
    double& balance = (*u)->getBalance();

    std::vector<Product*> copy = cart->second;

    // buy cart
    for (std::vector<Product*>::iterator it = copy.begin();
        it != copy.end();
        ++it) {
        if (balance - (*it)->getPrice() < 0) {
            continue;
        }
        // remove from balance and remove from cart
        balance -= (*it)->getPrice();
        cart->second.erase(cart->second.find(*it));
    }
}

