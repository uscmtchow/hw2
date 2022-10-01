#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"

struct Clothing : public Product {
public:
    Clothing(std::string size_, std::string brand_);
    std::set<std::string> keywords() const
    std::string displayString() const;
    void dump(std::ostream& os) const;
private:
    std::string size, brand;
};


#endif //CLOTHING_H
