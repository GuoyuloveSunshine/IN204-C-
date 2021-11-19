#ifndef MATH_HPP
#define MATH_HPP

#include <exception>
#include <stdexcept>

class division_by_zero: public std::runtime_error{
    public:
        division_by_zero(): std::runtime_error("DIVISION BY 0"){};

};
double divide(double a, double b) throw(division_by_zero);
double divide2(double a, double b) throw(division_by_zero);


#endif
