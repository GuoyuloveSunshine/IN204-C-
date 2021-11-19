#ifndef EXTEND_EXCEPTION_HPP_INCLUDED
#define EXTEND_EXCEPTION_HPP_INCLUDED

#include <exception>
#include <stdexcept>
#include <string>


class extend_exception: public std::runtime_error{
    private:
        int time = 0;
    public:
        explicit extend_exception(const std::string &aMessage): std::runtime_error(aMessage){};
        explicit extend_exception(const char* aMessage): std::runtime_error(aMessage){};
        void catched(){ time++; }
        int getCatchNumber() const{ return time;}

};


class extend_divide_by_zero: public extend_exception{
    public:
        explicit extend_divide_by_zero():extend_exception("division by zero"){};
};

double successive_division(double i) noexcept(false);
#endif // EXTEND_EXCEPTION_HPP_INCLUDED
