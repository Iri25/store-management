#pragma once
#include <assert.h>
#include "Product.h"
#include "Repository.h"
#include "TestRepository.h"

TestRepository::TestRepository()
{
	
}

TestRepository::~TestRepository()
{

}

void TestRepository::testAddElem()
{
	char name1[6] = "Skirt";
	char name2[9] = "Coverall";

	Product product1(name1, 60, 20);
	Product product2(name2, 150, 40);

	repository.addElem(product1);
	repository.addElem(product2);

	assert(repository.getSize() == 2);
}

void TestRepository::testUpdateElem()
{
	char name1[6] = "Skirt";
	char name3[9] = "T-shirt";

	Product product1(name1, 60, 20);
	Product product3(name3, 35, 10);

	repository.updateElem(product1, product3);
	repository.delElem(product1);
	repository.addElem(product3);

	assert(product1 == product3);
	assert(repository.getSize() == 2);
}

void TestRepository::testDelElem()
{
	char name2[9] = "Coverall";
	Product product2(name2, 150, 40);

	repository.delElem(product2);

	assert(repository.getSize() == 1);
}

void TestRepository::testGetAll()
{
	set<Product> result = repository.getAll();

	assert(result.size() == 1);
}

void TestRepository::testGetSize()
{
	set<Product> result = repository.getAll();

	assert(result.size() == 1);
}

void TestRepository::testFindElem()
{
	char name3[9] = "T-shirt";
	Product product3(name3, 35, 10);

	assert(repository.findElem(product3) != NULL);
}

void TestRepository::testElemAtPosition()
{
	int i = 0;
	char name3[9] = "T-shirt";
	Product product3(name3, 35, 10);

	assert(repository.elemAtPosition(i) == product3);
	assert(repository.findElem(product3) != -1);
}

void TestRepository::runTestRepository()
{
	void testAddElem();
	void testUpdateElem();
	void testDelElem();

	void testGetAll();
	void testGetSize();

	void testFindElem();
	void testElemAtPosition();
}


