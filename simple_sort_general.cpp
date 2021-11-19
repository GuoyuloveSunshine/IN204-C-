#include"simple_sort_general.hpp"
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<random>


namespace generic{
    template<typename T, typename genType>
    void populate_with_randoms(std::vector<T>& theVector,size_t theNumberOfValues,
                                genType theMinValue, genType theMaxValue){
//        int width = theMinValue - theMinValue;
//        for (int i = 0; i< theNumberOfValues;i++) {
//            theVector.push_back(theMinValue+(rand()%width));
        std::random_device rd;
        std::minstd_rand gen(rd());
        std::uniform_int_distribution<genType> distribution(theMinValue, theMaxValue);
        theVector.clear();
        for(;theNumberOfValues > 0;theNumberOfValues--){
            theVector.push_back(distribution(gen));
        }
    }

    template<typename T>
    void print_vector(const std::vector<T>& anArray){
        int length = anArray.size();
        std::cout << "[";
        for( int i = 0;i <length-1;i++){
            std::cout << anArray[i] << ", ";
        }
        std::cout << anArray[length-1] << "]" << std::endl;
    }
    template<typename T>
    void simple_sort(std::vector<T>& theValues){
        for(int i=0;i<theValues.size();i++){
            for(int j=i+1; j<theValues.size();j++){
                if(theValues[i]>theValues[j]){
                    std::swap(theValues[i], theValues[j]);
                }
            }
        }
    }
}
