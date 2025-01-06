#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class Array {
	T *elements;
	unsigned int size;

public:
	// Default constructor
	Array() : elements(nullptr), size(0) {
	}

	// Parameterized constructor
	explicit Array(const unsigned int n) : size(n) {
		elements = new T[n]();
	}

	// Copy constructor
	Array(const Array &other) : size(other.size) {
		elements = new T[other.size];
		for (unsigned int i = 0; i < other.size; ++i) {
			elements[i] = other.elements[i];
		}
	}

	// Destructor
	~Array() {
		delete[] elements;
	}

	// Assignment operator
	Array &operator=(const Array &other) {
		if (this != &other) {
			delete[] elements;
			size = other.size;
			elements = new T[other.size];
			for (unsigned int i = 0; i < other.size; ++i) {
				elements[i] = other.elements[i];
			}
		}
		return *this;
	}

	// Access operator
	T &operator[](unsigned int index) {
		if (index >= size) {
			throw std::out_of_range("Index out of range");
		}
		return elements[index];
	}

	// Const access operator
	const T &operator[](unsigned int index) const {
		if (index >= size) {
			throw std::out_of_range("Index out of range");
		}
		return elements[index];
	}

	// Get size of the array
	[[nodiscard]] unsigned int getSize() const {
		return size;
	}
};
