#include<iostream>
#include<thread>

#include "partie_1.hpp"
void test1(){
	std::thread simpleThread(&simple_method);
	std::cout << "Main thread is executing and waiting\n";
	simpleThread.join();
	std::cout << "Alternate thread has terminated.\n";
}

void test2(){
    std::thread t1(worker_process,50);
    std::thread t2(main_process);
    t1.join();
    t2.join();
}


int main(){
    //test1();
    test2();
    return 0;

}
