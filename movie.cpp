#include "movie.h"

Movie::Movie(std::string genre_, std::string rating_) : genre(genre_), rating(rating_) {}

std::set<std::string> Book::keywords() const {
    std::set<std::string> temp;
    temp.insert(genre);
    return temp;
}

std::string displayString() const {
    return std::string temp = category_ << "\n" << this->name_ << "\n" << this->price_ << "\n" << this->qty_ << "\n"
            << this->genre << "\n" << this->rating << std::endl;
}

void dump(std::ostream& os) const {
    os << category_ << "\n" << this->name_ << "\n" << this->price_ << "\n" << this->qty_ << "\n" << this->genre << "\n"
       << this->rating << endl;
}