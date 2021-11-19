#include "partie_2.hpp"
#include "mutex.hpp"
#include <iostream>
#include <algorithm>
#include <thread>

void test_valid_execution(std::vector<int>& theArray){
	// Get the max value of the array
	int referenceMaxValue = *(std::max_element(theArray.begin(), theArray.end()));
	int maxValue;
    array_find_max(theArray.begin(), theArray.end(), &maxValue);
	if (referenceMaxValue != maxValue){
		std::cout << "Error when computing the max value: " << maxValue
            << " found, " << referenceMaxValue << std::endl;
	}
	else{
        std::cout << "Good results: " << maxValue << std::endl;
	}

	array_multiply_by(theArray.begin(), theArray.end(), 2);
    array_find_max(theArray.begin(), theArray.end(), &maxValue);
	if (2*referenceMaxValue != maxValue){
		std::cout << "Error when computing the max value *2: " << maxValue
            << " found, " << 2*referenceMaxValue << std::endl;
	}
    else{
        std::cout << "Good results *2: " << maxValue << std::endl;
	}
}


void test_valid_execution_parallel(std::vector<int>& theArray){
	// Get the max value of the array
	int referenceMaxValue = *(std::max_element(theArray.begin(), theArray.end()));

	// Execute both threads in parallel
	int maxValue;
	std::thread find_max(&array_find_max,theArray.begin(), theArray.end(), &maxValue);
	array_multiply_by(theArray.begin(), theArray.end(), 2);
	find_max.join();
	int new_MaxValue = *(std::max_element(theArray.begin(), theArray.end()));

	if (referenceMaxValue != maxValue){
		std::cout << "Error when computing the max value: " << maxValue
            << " found, " << referenceMaxValue << std::endl;
	}
	else{
        std::cout << "Good results: " << maxValue << std::endl;
	}
}

void test_valid_execution_parallel_lock(std::vector<int>& theArray){

	// Get the max value of the array
	int referenceMaxValue = *(std::max_element(theArray.begin(), theArray.end()));

	// Execute both threads in parallel
	int maxValue;
	std::thread find_max(&array_find_max_lock,theArray.begin(), theArray.end(), &maxValue);
	array_multiply_by_lock(theArray.begin(), theArray.end(), 2);
	find_max.join();
	int new_MaxValue = *(std::max_element(theArray.begin(), theArray.end()));

	if (referenceMaxValue != maxValue){
		std::cout << "Error when computing the max value: " << maxValue
            << " found, " << referenceMaxValue << std::endl;
	}
	else{
        std::cout << "Good results: " << maxValue << std::endl;
	}
}

int main(){
	std::vector<int> array;
	initialize_array(array, 10000, 100);
//	test_valid_execution(array);
    std::cout<<"--------------------------------------------\n";
	test_valid_execution_parallel(array);
	std::cout<<"--------------------------------------------\n";
    initialize_array(array, 10000, 100);
	test_valid_execution_parallel_lock(array);
	return 0;
}
