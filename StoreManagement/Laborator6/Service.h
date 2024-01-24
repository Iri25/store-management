#pragma once
#pragma once
#include <set>
#include "Product.h"
#include "RepositoryFile.h"

using namespace std;

class Service
{
private:
	RepositoryFile<Product> repository;
public:
	Service();
	Service(const RepositoryFile<Product>& repository);
	~Service();

	void setRepository(const RepositoryFile<Product>& repository);

	void addElem(const Product& product);
	void updateElem(const Product& product1, const Product& product2);
	void delElem(const Product& product);

	set<Product>& getAll();
	int getSize();

	void buyElem(int& n, Product products[], int& lenght, Product results[], int ok_product[], int ok_name[], int ok_number[]);
	void returnElem(int& n, Product products[], int& lenght, Product results[], int ok_product[], int ok_number[]);
};