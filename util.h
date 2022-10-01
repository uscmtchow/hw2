#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> intersection;
    for (typename std::set<T>::iterator its1 = s1.begin();
        its1 != s1.end();
        ++its1) {
			if (s2.find(its1) != s2.end()) intersection.insert(s1);
    }
    return intersection;
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> unionSet;
    for (typename std::set<T>::iterator its1 = s1.begin();
        its1 != s1.end();
        ++its1) unionSet.insert(its1);
    for (typename std::set<T>::iterator its2 = s2.begin();
        its2 != s2.end();
        ++its2) unionSet.insert(its2);
    return union;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
