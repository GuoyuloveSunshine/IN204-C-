#ifndef counterHPP
#define counterHPP

#include <iostream>
using namespace std;

struct MyCounter{
    public:
        MyCounter(): counter(0), max(0){};
        explicit MyCounter(unsigned int theMaxValue):counter(0), max(theMaxValue){};
        MyCounter(unsigned int theCounter, unsigned int theMaxValue):counter(theCounter), max(theMaxValue){};
        MyCounter( const MyCounter &another):counter(another.counter),max(another.max){};
        ~ MyCounter(){
            cout<<"fini"<<endl;
        }

    unsigned counter;
    unsigned max;
    unsigned getCounter();
    unsigned getMax();
    void increment();
    void reset();
    void set(unsigned value);
    void setMax(unsigned value);

};

#endif
