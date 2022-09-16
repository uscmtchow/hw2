#include "book.h"

Book::Book(std::string ISBN_, std::string author_) : ISBN(ISBN_), author(author_) {}

std::set<std::string> Book::keywords() const {
    std::set<std::string> temp;
    temp.insert(this->ISBN);
    // CUT AUTHOR NAME IN HALF
    temp.insert(this->author);
    temp.insert(ltrim(this->auther));
    temp.insert(rtrim(this->author));
    return temp;
}

std::string displayString() const {
    return std::string temp = category_ << "\n" << this->name_ << "\n" << this->price_ << "\n" << this->qty_ << "\n"
            << this->ISBN << "\n" << this->author << std::endl;
}

void dump(std::ostream& os) const {
    os << category_ << "\n" << this->name_ << "\n" << this->price_ << "\n" << this->qty_ << "\n" << this->ISBN << "\n"
    << this->author << endl;
}
