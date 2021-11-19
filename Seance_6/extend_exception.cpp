#include "extend_exception.hpp"
#include <iostream>
#include "math.hpp"

double successive_division(double i) noexcept(false){
    double j;
    std::cout << "Next divisor (-1 to stop sequence): ";
    std::cin >> j;
    if (j == -1) return i;
    try{
        successive_division(j);
        double num = divide2(i,j);
        return num;
    }
    catch(division_by_zero e){
        throw extend_divide_by_zero();
    }
    catch (extend_divide_by_zero e){
        e.catched();
        throw e;
    }
}
