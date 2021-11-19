#ifndef counterHPP
#define counterHPP

struct MyCounter{
    protected:
        unsigned counter;
        unsigned max;
    public:
        // Effectue un appel au constructeur MyCounter(uint, uint)
        MyCounter(): counter(0), max(0){};
        MyCounter(int theCounter, int theMaxValue): counter(theCounter), max(theMaxValue){};
        MyCounter(const MyCounter &Counter): counter(Counter.counter), max(Counter.max){};
        MyCounter(int theMaxValue):counter(0), max(theMaxValue){};


    unsigned getCounter();
    unsigned getMax();
    void increment();
    void reset();
    void set(unsigned value);
    void setMax(unsigned value);
    void print();
};

#endif
