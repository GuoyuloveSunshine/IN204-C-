#ifndef SIMPLE_SORT_GENERAL_HPP_INCLUDED
#define SIMPLE_SORT_GENERAL_HPP_INCLUDED

#include <vector>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<random>



namespace generic{
    template<typename T, typename genType>
    void populate_with_randoms(std::vector<T>& theVector,size_t theNumberOfValues,
                                genType theMinValue, genType theMaxValue){
        std::random_device rd;
        std::minstd_rand gen(rd());
        std::uniform_real_distribution<double> distribution(theMinValue, theMaxValue);
        theVector.clear();
        for(;theNumberOfValues > 0;theNumberOfValues--){
            theVector.push_back((genType)distribution(gen));
        }
    }

    template<>
    void populate_with_randoms(std::vector<std::string>& theVector,
        size_t theNumberOfValues, int theMinValue, int theMaxValue){
        // Initialise le générateur de nombres aléatoires
        // et définit la loi de distribution uniforme.
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int>distribution(theMinValue, theMaxValue);

        char buffer[20];

        //int width = theMaxValue - theMinValue;
        for(;theNumberOfValues > 0;theNumberOfValues--){
            int randValue = distribution(generator);
            std::sprintf(buffer,"%d",randValue);
            std::string stringValue = buffer;
            theVector.push_back(stringValue);
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
    struct greater_traits{
        public:
            static bool is_greater(T aValue, T anotherValue) {
                return aValue > anotherValue;
            }
    };

    template<typename T>
    struct lower_traits{
        public:
            static bool is_greater(T aValue, T anotherValue) {
                return aValue < anotherValue;
            }
    };


    template<typename T, typename sortTaits = greater_traits<T>>
    void simple_sort(std::vector<T>& theValues, sortTaits traits = sortTaits()){
        int length = theValues.size();
        for(int i = 0; i< length-1; i++){
            for(int j=i+1; j<length; j++){
                if(traits.is_greater(theValues[i], theValues[j])){
                    std::swap(theValues[i], theValues[j]);
                }
            }
        }
    }

}

#endif // SIMPLE_SORT_GENERAL_HPP_INCLUDED
