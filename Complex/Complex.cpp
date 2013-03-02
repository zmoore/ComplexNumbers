// Complex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Complex.h"
#include <iostream>
#include <string>

int main(){
	complex<int> f(1,2), g(2,3);
//	f = 5*f;
	std::string temp = f;
	std::cout << temp;
	f = f + 2;
	temp = f;
	std::cout << temp;
	f = 5 + f;
	temp = f;
	std::cout << temp;
	return 0;
}

