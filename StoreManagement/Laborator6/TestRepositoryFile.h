#pragma once
#include "Product.h"
#include "RepositoryFile.h"

class TestRepositoryFile
{
private:
	RepositoryFile<Product> repository;

	void testAddElem();
	void testUpdateElem();
	void testDelElem();

	void testGetAll();

public:
	TestRepositoryFile();
	~TestRepositoryFile();

	void testLoadFromFile();
	void testSaveToFile();

	void runTestRepositoryFile();
};