#ifndef basecounterHPP
#define basecounterHPP

#include "counter.hpp"
#include <iostream>
using namespace std;

class BaseCounter: public MyCounter{
    public:
        BaseCounter():MyCounter(){};
        BaseCounter(unsigned maxvalue): MyCounter(0,maxvalue){};
        BaseCounter(unsigned int c, unsigned int theMax): MyCounter(c,theMax){};
        BaseCounter(const BaseCounter & aCounter): MyCounter(aCounter){};
        ~BaseCounter(){
            cout << "Destruction: BaseCounter@" << this << endl;
        }
        void print(){
            cout << "MyBaseCompteur: " << counter << "/" << max << endl;
        }
};

class ForwardCounter: public virtual BaseCounter{
    public:
        ForwardCounter(): BaseCounter() {};
        ForwardCounter(const ForwardCounter& aCounter): BaseCounter(aCounter) {};
        explicit ForwardCounter(unsigned theMaxValue): ForwardCounter(0, theMaxValue) {};
        ForwardCounter(unsigned theCounter, unsigned theMaxValue): BaseCounter(theCounter, theMaxValue) {};
        ~ForwardCounter()
        {
            cout << "Destruction: ForwardCounter@" << this << endl;
        }
        void increment(){
            if(counter < max) counter = counter + 1;
            else counter = 0;
        }
};

class BackwardCounter: public virtual BaseCounter{
    public:
        BackwardCounter(): BaseCounter() {};
        BackwardCounter(const BackwardCounter& aCounter): BaseCounter(aCounter) {};
        explicit BackwardCounter(unsigned theMaxValue): BackwardCounter(0, theMaxValue) {};
        BackwardCounter(unsigned theCounter, unsigned theMaxValue): BaseCounter(theCounter, theMaxValue) {};
        ~BackwardCounter(){
            cout << "Destruction: BackwardCounter@" << this << endl;
        }
        void decrement(){
            if(counter > 0) counter = counter -1;
            else counter = max;
        }
};

class BiDiCounter: public BaseCounter{
    public:
        BiDiCounter(): BaseCounter() {};
        BiDiCounter(const BiDiCounter& aCounter): BaseCounter(aCounter) {};
        explicit BiDiCounter(unsigned theMaxValue): BiDiCounter(0, theMaxValue) {};
        BiDiCounter(unsigned theCounter, unsigned theMaxValue): BaseCounter(theCounter, theMaxValue) {};
        ~BiDiCounter(){
            cout << "Destruction: BiDiCounter @" << this << endl;
        }
        void increment(){
            if(counter < max) counter = counter + 1;
            else counter = 0;
        }
        void decrement(){
            if(counter > 0) counter = counter -1;
            else counter = max;
        }
};



class MyAdvCounter: public MyCounter{
public:
    MyAdvCounter(): MyCounter() {}
    explicit MyAdvCounter(unsigned theMax): MyCounter(theMax){}
    MyAdvCounter(unsigned theCounter,unsigned theMax): MyCounter(theCounter, theMax){}
    MyAdvCounter(const MyCounter& anotherCounter): MyCounter(anotherCounter){}

    void increment(){
        if(counter < max)
            counter ++;
    }
    void print() const{
        std::cout << "MyAdvCompteur: " << counter << "/" << max << std::endl;
    }
};

#endif
