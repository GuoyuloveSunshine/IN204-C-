#include "counter.hpp"
#include <iostream>

unsigned MyCounter::getCounter(){
        return counter;
}
unsigned MyCounter::getMax(){
        return max;
}
void MyCounter::increment() {
        counter ++;
        if(counter > max) counter = 0;
}
void MyCounter::reset() {
        counter = 0;
}
void MyCounter::set(unsigned value) {
        counter = (value <= max) ? value : counter;
}
void MyCounter::setMax(unsigned value) {
        if(counter >= value)counter = 0;
        max = value;
}
void MyCounter::print(){
        std::cout << "MyCompteur: " << counter << "/" << max << std::endl;
}

