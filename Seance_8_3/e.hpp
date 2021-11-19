#ifndef E_HPP_INCLUDED
#define E_HPP_INCLUDED

#include <string>
#include <iostream>
#include <sstream>
#include <mutex>

std::string computeE(int numberOfDigits){


	int sizeOfTable = numberOfDigits + 9;
	int* table = (int*)alloca(sizeOfTable * sizeof(numberOfDigits));
	table[0] = 0;
	table[1] = 2;
	for (int i = sizeOfTable - 1; i > 0; i--) {
		table[i] = 1;
	}

	std::ostringstream output;
	int x = 0;
	table[1] = 2;
	for (; sizeOfTable > 9; sizeOfTable -- )
	{
		for (int i = sizeOfTable - 1; i > 0; i--)
		{
			table[i] = x % i;
			x = 10 * table[i - 1] + x / i;
		}
		output << x;
	}
	return output.str();
}

#endif // E_HPP_INCLUDED
