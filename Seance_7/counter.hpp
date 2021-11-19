#ifndef COUNTER_HPP_INCLUDED
#define COUNTER_HPP_INCLUDED
#include <iostream>
#include <string>

class BaseCounter{
    protected:
        unsigned counter;
        unsigned max;
    public:
        unsigned getCounter() const { return counter; }
        unsigned getMax() const { return max; }
        void reset() { counter = 0; }
        void set(unsigned value) { counter = value; }
        void setMax(unsigned value)
        {
            max = value;
            if(value > counter)
                counter = counter % max;
        }
        virtual void next() = 0;
        virtual void next(unsigned) = 0;
        virtual std::string get_classname() const = 0;
    protected:
        BaseCounter(): counter(0), max(0) {}
        BaseCounter(unsigned theCounter,
            unsigned theMax): counter(theCounter), max(theMax){ std::cout<<"   Base\n";}
        explicit BaseCounter(unsigned theMax):
            max(theMax), counter(0){}
        BaseCounter(const BaseCounter& anotherCounter):
            counter(anotherCounter.counter),
            max(anotherCounter.max){}
        ~BaseCounter(){}
        template<class charT, class charTraits>
        friend std::basic_ostream<charT>& operator <<(std::basic_ostream<charT, charTraits>& aStream, const BaseCounter& aCounter);

};




class ForwardCounter: public virtual BaseCounter{
    public:
        virtual void increment(){
            if(counter < max)
                counter = counter + 1;
            else
                counter = 0;
        }

        ForwardCounter(): BaseCounter() {}
        ForwardCounter(const ForwardCounter& aCounter): BaseCounter(aCounter) {}
        explicit ForwardCounter(unsigned theMaxValue): ForwardCounter(0, theMaxValue) {}
        ForwardCounter(unsigned theCounter, unsigned theMaxValue):BaseCounter(theCounter, theMaxValue) {std::cout<<"   Forward\n";}
        void next(){
            increment();
        }
        void next(unsigned num){
            for (int i = 0;i<num;i++){
                increment();
            }
        }
        std::string get_classname()const { return "ForwardCounter";}
};

class VerboseForwardCounter: public ForwardCounter{
    public:
        void increment(){
            if (counter < max){
                counter = counter + 1;
            }
            else{
                std::cout << "Maximal value: " << max << " has been reached." << std::endl;
                counter = 0;
            }
        }

        VerboseForwardCounter() : ForwardCounter() { }
        VerboseForwardCounter(const ForwardCounter& aCounter) : ForwardCounter(aCounter) {}
        explicit VerboseForwardCounter(unsigned theMaxValue) : VerboseForwardCounter(0, theMaxValue) {}
        VerboseForwardCounter(unsigned theCounter, unsigned theMaxValue) :
            ForwardCounter(theCounter, theMaxValue),BaseCounter(theCounter, theMaxValue) {std::cout<<"   Verbose\n";}

};

class BackwardCounter: public virtual BaseCounter
{
    public:
        void decrement()
        {
            if(counter > 0)
                counter = counter -1;
            else
                counter = max;
        }
        BackwardCounter(): BaseCounter() {}
        BackwardCounter(const ForwardCounter& aCounter): BaseCounter(aCounter) {}
        explicit BackwardCounter(unsigned theMaxValue): BackwardCounter(0, theMaxValue) {}
        BackwardCounter(unsigned theCounter, unsigned theMaxValue): BaseCounter(theCounter, theMaxValue) {}
        void next(){
            decrement();
        }
        void next(unsigned num){
            for(int i = 0;i<num;i++){
                decrement();
            }
        }
        std::string get_classname()const { return "BackwordCounter";}
};

class BiDiCounter: public ForwardCounter, public BackwardCounter{
    public:
        BiDiCounter(): ForwardCounter(), BackwardCounter() {}
        BiDiCounter(const BiDiCounter& aCounter): ForwardCounter(aCounter),
            BackwardCounter((const BackwardCounter&)aCounter),BaseCounter(aCounter) {}
        BiDiCounter(unsigned theMaxValue): BiDiCounter(0, theMaxValue) {}
        BiDiCounter(unsigned theCounter, unsigned theMaxValue): ForwardCounter(theCounter, theMaxValue),
            BackwardCounter(theCounter, theMaxValue), BaseCounter(theCounter, theMaxValue) {}
        void next(){
            ForwardCounter::next();
        }
        void next(unsigned num){
            ForwardCounter::next(num);
        }
        std::string get_classname()const { return "BiDiCounter";}
};
void testNext(BaseCounter&);
void testForwardCounter(ForwardCounter&);
#endif // COUNTER_HPP_INCLUDED
