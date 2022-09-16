#include "clothing.h"

Clothing::Clothing(std::string size_, std::string brand_) : size(size_), brand(brand_){}

std::set<std::string> Clothing::keywords() const {
    std::set<std::string> temp;
    temp.insert(this->size);
    temp.insert(this->brand);
    // split brand
    temp.insert(ltrim(this->brand));
    temp.insert(rtrim(this->brand));
    return temp;
}

std::string displayString() const {
    return std::string temp = category_ << "\n" << this->name_ << "\n" << this->price_ << "\n" << this->qty_ << "\n "
            << this->size << "\n" << this->brand << std::endl;
}

void dump(std::ostream& os) const {
    os << category_ << "\n" << this->name_ << "\n" << this->price_ << "\n" << this->qty_ << "\n" << this->size << "\n"
       << this->brand << endl;
}
