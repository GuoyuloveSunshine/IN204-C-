#ifndef MUTEX_HPP_INCLUDED
#define MUTEX_HPP_INCLUDED

#include <random>
#include <vector>
#include <mutex>
std::mutex mtx;           // mutex fournissant le mécanisme d’exclusion mutuelle.

void array_find_max_lock(std::vector<int>::const_iterator begin,
	std::vector<int>::const_iterator end, int* theMaxValue){
	std::unique_lock<std::mutex> lock(mtx);
	if (begin != end){
		int result = *begin;
		begin++;
		for (; begin != end; begin++){
            if (*begin > result) result = *begin;
		}
        *theMaxValue = result;
	}
}

void array_multiply_by_lock(std::vector<int>::iterator begin,
	std::vector<int>::iterator end, int theValue){
	std::unique_lock<std::mutex> lock(mtx);
	for (; begin != end; begin++){
		*begin *= theValue;
	}
}


#endif // MUTEX_HPP_INCLUDED
