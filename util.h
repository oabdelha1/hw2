#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */

/*
template <typename T>
std::set<T> setIntersection(typename std::set<T>& s1, typename std::set<T>& s2)
{
     std::set<T> output;
     typename std::set<T>::iterator it;
    for (it = s1.begin(); it != s1.end(); it++){
        std::cout << "Iterator at: " << &it << std::endl;
        output.insert(*it);
    }
    for (it = s2.begin(); it != s2.end(); it++){
        std::cout << "Iterator at: " << &it << std::endl;
        output.insert(*it);
    }

    return output;
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> output;
    typename std::set<T>::iterator it;
    for (it = s1.begin(); it != s1.end(); it++){
        typename T x = *it;
        typename std::set<T>::iterator check;
        check = s2.find(x);

        if (check != s2.end()){
            output.insert(check);
        }
    }

}
*/

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
