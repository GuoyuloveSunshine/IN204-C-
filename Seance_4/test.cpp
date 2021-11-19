#include<algorithm>
#include<iostream>
#include<vector>

#include "iterateur.hpp"
#include"interval.hpp"

void test_max(){
	int myints[] = { 10,20,30,30,20,10,10,20 };
	std::vector<int> v(myints, myints + 8);
	int maxValue;
	std::vector<int>::iterator up = find_the_greatest(v.begin(), v.end(), maxValue);
	std::cout << "the greatest value is :" << maxValue <<
	 ", at the  position : " << (up - v.begin()) << '\n';
}

void test_upper(){
	int myints[] = { 10,20,30,30,20,10,10,20 };
	//int myints[] = { 10,0,0,0,20,10,10,20 };
	std::vector<int> v(myints, myints + 8);
	std::cout << "The list: ";
	print(v);
	std::cout << std::endl;
	std::vector<int>::iterator up = upper(v.begin(), v.end(), 20);
	print(v);
	std::cout << std::endl;
	std::cout << "First value greater than 20  at position "
            << (up - v.begin()) << '\n';
}



void testInterval(){
    interval inter(5, 15);
    std::cout << "Contenu de l'interval : ";
    print(inter.begin(), inter.end());
    // Recherche du plus grand élément.
    auto maxIt = max_element(inter.begin(), inter.end());
    std::cout << "Element maximal de la séquence: " << *maxIt << std::endl;
    // Duplication des valeurs dans un vecteur
    std::vector<int> vec(inter.begin(), inter.end());
    std::cout << "Contenu du vecteur : ";
    print(vec.begin(), vec.end());
}


int main(){
    //test_max();
    //test_upper();
    testInterval();
    return 0;
}
