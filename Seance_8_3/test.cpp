#include "e.hpp"
#include <iostream>
#include <string>
#include <future>



void display(std::future<std::string>& aFutureValue, int theDecimals){
	aFutureValue.wait();
	std::cout << "e with " << theDecimals << " decimals\n" << aFutureValue.get() << std::endl;
}

int main(){
	std::future<std::string> eWidth20000 = std::async(std::launch::async, &computeE, 20000);
	std::future<std::string> eWidth100000 = std::async(std::launch::async, &computeE, 100000);
	display(eWidth20000, 20000);
	display(eWidth100000, 100000);
}
