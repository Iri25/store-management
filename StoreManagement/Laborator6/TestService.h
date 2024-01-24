#pragma once
#include "Product.h"
#include "Service.h"

class TestService
{
private:
	Service service;

	void testAddElem();
	void testUpdateElem();
	void testDelElem();

	void testGetAll();
	void testGetSize();

	void testBuyElem();
	void testReturnElem();
public:
	void runTestService();
};