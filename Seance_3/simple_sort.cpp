#include"simple_sort.hpp"
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<random>
//using namespace std;
namespace monomorphic{
    void populate_with_randoms(std::vector<int>& theVector,int theNumberOfValues,
                                int theMinValue, int theMaxValue){
//        int width = theMinValue - theMinValue;
//        for (int i = 0; i< theNumberOfValues;i++) {
//            theVector.push_back(theMinValue+(rand()%width));
        std::random_device rd;
        std::minstd_rand gen(rd());
        std::uniform_int_distribution<int> distribution(theMinValue, theMaxValue);
        theVector.clear();
        for(;theNumberOfValues > 0;theNumberOfValues--){
            theVector.push_back(distribution(gen));
        }
    }


    void print_vector(const std::vector<int>& anArray){
        int length = anArray.size();
        std::cout << "[";
        for( int i = 0;i <length-1;i++){
            std::cout << anArray[i] << ", ";
        }
        std::cout << anArray[length-1] << "]" << std::endl;
    }
    void simple_sort(std::vector<int>& theValues){
        int length = theValues.size();
        for(int i = 0;i < length-1;i++){
            for(int j = i+1; j < length;j++){
                if(theValues[i] > theValues[j]){
                    std::swap(theValues[i], theValues[j]);
                }
            }
        }
    }
}
