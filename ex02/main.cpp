#include <iostream>
#include "Array.hpp"

void testArray() {
	try {
		// Test default constructor
		const Array<int> defaultArray;
		std::cout << "Default array size: " << defaultArray.getSize() << std::endl;

		// Test parameterized constructor
		Array<int> paramArray(5);
		std::cout << "Parameterized array size: " << paramArray.getSize() << std::endl;

		// Test element access and modification
		for (unsigned int i = 0; i < paramArray.getSize(); ++i) {
			paramArray[i] = i * 10;
		}
		std::cout << "Parameterized array elements: ";
		for (unsigned int i = 0; i < paramArray.getSize(); ++i) {
			std::cout << paramArray[i] << " ";
		}
		std::cout << std::endl;

		// Test copy constructor
		Array copyArray(paramArray);
		std::cout << "Copy array elements: ";
		for (unsigned int i = 0; i < copyArray.getSize(); ++i) {
			std::cout << copyArray[i] << " ";
		}
		std::cout << std::endl;

		// Modify original array and show that copy is unaffected
		paramArray[0] = 100;
		std::cout << "Modified original array elements: ";
		for (unsigned int i = 0; i < paramArray.getSize(); ++i) {
			std::cout << paramArray[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Unmodified copy array elements: ";
		for (unsigned int i = 0; i < copyArray.getSize(); ++i) {
			std::cout << copyArray[i] << " ";
		}
		std::cout << std::endl;

		// Test assignment operator
		Array<int> assignArray = paramArray;
		std::cout << "Assigned array elements: ";
		for (unsigned int i = 0; i < assignArray.getSize(); ++i) {
			std::cout << assignArray[i] << " ";
		}
		std::cout << std::endl;

		// Test out-of-range exception
		try {
			std::cout << paramArray[10] << std::endl;
		} catch (const std::out_of_range &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int main() {
	testArray();
	return 0;
}
