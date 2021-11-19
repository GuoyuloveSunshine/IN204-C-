void myfunctionA() {
    MyCounter counter;
    std::cout << counter.getCounter() << std::endl;
    std::cout << counter.getMax() << std::endl;
}
void myfunctionB() {
    MyCounter* counter = new MyCounter();
    std::cout << counter->getCounter() << std::endl;
    std::cout << counter->getMax() << std::endl;
    delete counter;
}
