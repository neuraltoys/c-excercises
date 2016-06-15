#include "unique_pointer.h"

#include <string>
#include <cassert>
#include <iostream>
#include <cstring>

//template<typename UniquePointerType<std::string>>
//void string_test()
//{
//	// Default construction
//	UniquePointerType<std::string> unq_ptr;
//
//	// default created object is empty
//	assert(string1.empty());
//	assert(string1.size() == 0);
//
//	// Initilized from string literal
//	UniquePointerType string2("Hey");
//
//	assert(!string2.empty());
//	assert(string2.size() == 3);
//
//	// Copy-construction
//	UniquePointerType string3 = string2;
//
//	assert(string2 == string3);
//	assert(string3.size() == 3);
//
//	// read-only character access
//
//	assert(string3[0] == 'H');
//	assert(string3[1] == 'e');
//	assert(string3[2] == 'y');
//
//	// writable charactetr acess
//	string2[2] = 'x';
//	assert(string2 == "Hex");
//
//	// copy is deep, so string3 remains unchanged
//	assert(string3 == "Hey");
//	assert(string2 != string3);
//
//	// const-correctness test
//	const StringType& string_const_ref = string3;
//	assert(string_const_ref.empty() == false);
//	assert(string_const_ref.size() == 3);
//	assert(string_const_ref[0] == 'H');
//
//	// c_str test
//	assert(std::strcmp(string_const_ref.c_str(), "Hey") == 0);
//
//	// assignment operator test
//	string3 = "abc";
//	assert(string_const_ref == "abc");
//
//	string3 = string2;
//	assert(string_const_ref == "Hex");
//	assert(string2 == "Hex");
//
//	// operator +=
//	StringType plusResult = string_const_ref + StringType("123");
//	assert(plusResult == "Hex123");
//
//	// operator +=
//	plusResult += string2;
//	assert(plusResult == "Hex123Hex");
//}


int main()
{
	std::cout << "Testing UniquePointer..." << std::endl;

	std::string myteststring = "my test string";
	Maciek::UniquePointer<std::string> up1(&myteststring);

	std::cout << "UniquePointer test passes" << std::endl;
}