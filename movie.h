#ifndef MOVIE_H
#define MOVIE_H


struct Movie : class Product {
public:
    Movie(std::string genre_, std::string rating_);
    std::set<std::string> keywords() const
    std::string displayString() const;
    void dump(std::ostream& os) const;
private:
    std::string genre, rating;
};


#endif //MOVIE_H
