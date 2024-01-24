#include "TestRepositoryFile.h"
#include <cassert>
#include <iostream>

TestRepositoryFile::TestRepositoryFile()
{

}

TestRepositoryFile::~TestRepositoryFile()
{

}

void TestRepositoryFile::testLoadFromFile()
{
	repository.loadFromFile("TestProductsOut.txt");

	int n = repository.getSize();
	assert(repository.getSize() == n);
}

void TestRepositoryFile::testAddElem()
{
	repository.loadFromFile("TestProductsOut.txt");

	char name1[10] = "Coverall";
	char name2[6] = "Skirt";
	char name3[8] = "T-shirt";

	Product product1(name1, 150, 40);
	Product product2(name2, 60, 20);
	Product product3(name3, 35, 10);

	repository.addElem(product1);
	repository.addElem(product2);
	repository.addElem(product3);

	int n = repository.getSize();
	assert(repository.getSize() == n);

	repository.saveToFile();
}

void TestRepositoryFile::testUpdateElem()
{
	repository.loadFromFile("TestProductsOut.txt");

	char name1[10] = "Coverall";
	char name3[9] = "T-shirt";

	Product product1(name1, 150, 40);
	Product product3(name3, 35, 10);

	repository.updateElem(product1, product3);
	
	int n = repository.getSize();
	assert(repository.getSize() == n);

	repository.saveToFile();
}

void TestRepositoryFile::testDelElem()
{
	repository.loadFromFile("TestProductsOut.txt");

	char name1[10] = "Coverall";
	Product product1(name1, 150, 40);

	repository.delElem(product1);

	int n = repository.getSize();
	assert(repository.getSize() == n);

	repository.saveToFile();
}

void TestRepositoryFile::testGetAll()
{
	repository.loadFromFile("TestProductsOut.txt");

	set<Product> result = repository.getAll();

	int n = repository.getSize();
	assert(repository.getSize() == n);
}

void TestRepositoryFile::testSaveToFile()
{
	repository.loadFromFile("TestProductsOut.txt");

	int n = repository.getSize();
	assert(repository.getSize() == n);
}

void TestRepositoryFile::runTestRepositoryFile()
{
	testLoadFromFile();
	
	testAddElem();	
	
	testGetAll();

	testSaveToFile();
}
