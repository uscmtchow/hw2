#ifndef BOOK_H
#define BOOK_H

#include "product.h"

struct Book: class Product {
public:
    Book(std::string ISBN_, std::string author_);
    std::set<std::string> keywords() const
    std::string displayString() const;
    void dump(std::ostream& os) const;
private:
    std::string ISBN, author;
};


#endif //BOOK_H
