#ifndef iterateur_hpp
#define iterateur_hpp

#include <vector>       // std::vector
#include <algorithm>
#include <iostream>
template <class inputIterator, class T>
inputIterator find_the_greatest(inputIterator first, inputIterator last, T& theValue){
    if(first == last) return last;
    inputIterator greatest = first;
    theValue = *first;
    for(; first != last; first++){
        if (*first > theValue){
            greatest = first;
            theValue = *first;
        }
    }
    return greatest;
}

template <class inputIterator, class T>
inputIterator upper(inputIterator i_begin, inputIterator i_end, const T& theValue){
    sort(i_begin,i_end);
	for(;i_begin !=i_end;i_begin++){
        if(*i_begin > theValue){
            return i_begin;
        }
	}
	return i_end;
}

template<typename T>
void print(std::vector<T> vec){
    for (typename std:: vector<T>:: iterator it = vec.begin(); it != vec.end();it++){
        std::cout << *it <<", ";
    }
}

#endif
