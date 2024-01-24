#pragma once
#include "Product.h"
#include "Repository.h"

class TestRepository
{
private:
	Repository<Product> repository;
	
	void testAddElem();
	void testUpdateElem();
	void testDelElem();

	void testGetAll();
	void testGetSize();

	void testFindElem();
	void testElemAtPosition();
public:
	TestRepository();
	~TestRepository();

	void runTestRepository();
};