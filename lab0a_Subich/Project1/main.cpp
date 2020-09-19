#include "module1.h"
#include "module2.h"
#include "peter.h"
#include <iostream>

int main(int argc, char** argv) {
	std::cout << "Hello" << "\n";
	std::cout << Module1::getMyName() << "\n";
	std::cout << Module2::getMyName() << "\n";

	using namespace Module1;
	std::cout << getMyName() << "\n";
	std::cout << Module2::getMyName() << "\n";

	using Module2::getMyName;
	std::cout << getMyName() << "\n";

	std::cout << Peter::getMyName() << "\n";

}