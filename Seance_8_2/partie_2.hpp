#ifndef PARTIE_2_HPP_INCLUDED
#define PARTIE_2_HPP_INCLUDED

#include <random>
#include <vector>

void array_find_max(std::vector<int>::const_iterator begin,
	std::vector<int>::const_iterator end, int* theMaxValue){
	if (begin != end){
		int result = *begin;
		begin++;
		for (; begin != end; begin++){
            if (*begin > result) result = *begin;
		}
        *theMaxValue = result;
	}
}

void array_multiply_by(std::vector<int>::iterator begin,
	std::vector<int>::iterator end, int theValue){
	for (; begin != end; begin++){
		*begin *= theValue;
	}
}

void initialize_array(std::vector<int>& theArray, int theSize, int theMaxValue){
	theArray.clear();
    theArray.resize(theSize);
	int step = theMaxValue / 3;
	theArray[0] = 0;
	for (int i = 1; i < theSize; i++){
        theArray[i] = (theArray[i-1] + step) % (theMaxValue + 1);
	}
}



void initialize_random_array(std::vector<int>& theArray, int theSize, int theMaxValue){
	static std::mt19937 gen(1729);
	std::uniform_int_distribution<> distrib(0, theMaxValue);
	theArray.clear();
	for (int i = 0; i < theSize; i++){
		theArray[i] = distrib(gen);
	}
}

#endif // PARTIE_2_HPP_INCLUDED
