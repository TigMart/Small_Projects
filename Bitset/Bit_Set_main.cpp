// Bit_Set.cpp : 

#include <iostream>
#include "Bit_Set.h"

int main()
{
	BitSet<64> a(800000000);
	BitSet<64> b(5);
	std::string str = "1111111111111111111111111111111111111111111111111111111111111111111";
	BitSet<69> c(str);
	std::cout << c << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << b.operator~() << std::endl;
	std::cout << (a & b)<<std::endl;
}
