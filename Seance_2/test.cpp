#include "MyBiDiCounter.hpp"
#include "BaseCounter.hpp"

void testMyBiDiCounter()
{
    MyBiDiCounter counterA;
    counterA.setMax(4);
    counterA.reset();
    counterA.print();
    for(int i=0; i < 6; i++)
    {
        counterA.increment();
        counterA.print();
    }
    for(int i=0; i < 6; i++)
    {
        counterA.decrement();
        counterA.print();
    }
}

void testMyBiDiCounter2(){
    MyBiDiCounter counterA;
    counterA.set(1);
    counterA.setMax(6);


    MyBiDiCounter counterB(4);
    MyBiDiCounter counterC(2,4);
    MyBiDiCounter counterD(counterA);

}


void testFamilyOfCounters(){
    ForwardCounter incCounter(0, 4);
    BackwardCounter decCounter(0, 3);
    BiDiCounter biDiCounter(0, 5);
    for(int i=0; i < 6; i++){
        incCounter.increment();
        incCounter.print();
        decCounter.decrement();
        decCounter.print();
        biDiCounter.increment();
        biDiCounter.print();
    }
    for(int i=0; i < 6; i++){
        biDiCounter.decrement();
        biDiCounter.print();
    }
}

void testMyAdvCounter(){
    MyAdvCounter incCounter(0, 4);
    for(int i=0; i < 6; i++){
        incCounter.increment();
        incCounter.print();
    }
}

void testCounter(){
    MyCounter unCompteur(0,4);
    for(int i=0; i < 6; i++){
        unCompteur.increment();
        unCompteur.print();
    }
}

int main(){
    //testMyBiDiCounter();
    //testMyBiDiCounter2();
    testFamilyOfCounters();
    //testMyAdvCounter();
    //testCounter();
    return 0;
}
