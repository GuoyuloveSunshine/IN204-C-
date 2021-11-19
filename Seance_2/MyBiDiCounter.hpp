#ifndef mybidicounterHPP
#define mybidicounterHPP

#include "counter.hpp"
#include <iostream>
using namespace std;


class MyBiDiCounter: public MyCounter{
    public:
        //using MyCounter:: MyCounter;
        MyBiDiCounter(): MyCounter(){};
        MyBiDiCounter(unsigned maxvalue): MyCounter(0,maxvalue){};
        MyBiDiCounter(int c, int theMax): MyCounter(c,theMax){};
        MyBiDiCounter(const MyBiDiCounter & Counter): MyCounter(Counter){};


        void decrement(){
            if (counter == 0){
                counter = max;
            }
            else{
                counter --;
            }
        }
        void print(){
            cout << "Compteur: " << counter << "/" << max << endl;
        }
        void increment(unsigned value){
            if (counter +value <= max) counter +=value;
            else counter = (counter + value) % max;
        }

        using MyCounter::increment;
};


#endif
