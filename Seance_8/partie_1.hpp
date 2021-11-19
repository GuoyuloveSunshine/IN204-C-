#ifndef PARTIE_1_HPP_INCLUDED
#define PARTIE_1_HPP_INCLUDED

#include <iostream>
#include <thread>
#include <chrono>
void simple_method()
{
	int i = 5;
	int x = 10;
	int result = i * x;
	std::cout << "This code calculated the value "
		<< result << " from thread ID: "
		<< std::this_thread::get_id() << "\n";
}

void worker_process(int numberOfIterations){
	for (int i = 1; i < numberOfIterations; i++){
		std::cout << "Worker Thread: " <<  i << "\n";
		std::this_thread::sleep_for(std::chrono::seconds(10));
	}
}


void main_process(){
	for (int i = 1; i < 100; i++){
		std::cout << "Primary Thread: " << i << "\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}


#endif // PARTIE_1_HPP_INCLUDED
