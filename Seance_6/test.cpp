#include <iostream>
#include "math.hpp"
#include "extend_exception.hpp"


void test_divide() noexcept(false){
  double i, j;
  for(;;) {
    std::cout << "Le numerateur (0 pour arreter): ";
    std::cin >> i;
    if(i == 0)
      break;
    std::cout << " Le denominateur : ";
    std::cin >> j;
    std::cout << "Resultat: " << divide(i,j) << std::endl;
  }
}

void test_divide2() noexcept{
  double i, j;
  for(;;) {
    std::cout << "Le numerateur (0 pour arreter): ";
    std::cin >> i;
    if(i == 0) break;
    std::cout << " Le denominateur : ";
    std::cin >> j;
    try{
        double num = divide2(i,j);
        std::cout << "Resultat: " <<  num << std::endl;
    }
    catch(division_by_zero anException){
        std::cout << "Erreur: " << anException.what() << std::endl;
    }

  }
}


void test_succesive_division() noexcept{
	double i;
	std::cout << "The numerator: ";
	std::cin >> i;
	try {
		successive_division(i);
	}
	catch (extend_divide_by_zero e) {
		e.catched();
		std::cout << "Division by zero occurred after "
			<< e.getCatchNumber()
			<< " divisions" << std::endl;
	}
}



int main()
{
    //test_divide();
//    test_divide2();
    test_succesive_division();
    return 0;
}
