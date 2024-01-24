#pragma once
#include "Product.h"

class TestProduct
{
private:
	Product product;

	void testConstructor();

	void testOperator();

	void testGetName();
	void testGetPrice();
	void testGetNumber();

	void testSetName();
	void testSetPrice();
	void testSetNumber();
public:
	void runTestProduct();
};