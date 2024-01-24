#include"TestService.h"
#include<iostream>
#include<cassert>

void TestService::testAddElem()
{
	char name1[6] = "Boots";
	char name2[6] = "Shoes";

	Product product1(name1, 85, 12);
	Product product2(name2, 130, 10);

	service.addElem(product1);
	service.addElem(product2);

	assert(service.getSize() == 2);
}

void TestService::testUpdateElem()
{
	char name1[6] = "Boots";
	char name3[8] = "Sandals";

	Product product1(name1, 85, 12);
	Product product3(name3, 45, 5);

	service.updateElem(product1, product3);

	assert(product1 == product3);
	assert(service.getSize() == 2);
}

void TestService::testDelElem()
{
	char name2[6] = "Shoes";
	Product product2(name2, 130, 10);

	service.delElem(product2);

	assert(service.getSize() == 1);
}

void TestService::testGetAll()
{
	set<Product> result = service.getAll();

	assert(result.size() == 1);
}

void TestService::testGetSize()
{
	set<Product> result = service.getAll();

	assert(result.size() == 1);
}

void TestService::testBuyElem()
{
	int i, number_of_products, lenght = 0, ok_product[100], ok_name[100], ok_number[100];
	Product products[100], results[100];
	char buyProduct[8] = "Sandals";

	Product product(buyProduct, 0, 5);

	service.buyElem(number_of_products, products, lenght, results, ok_product, ok_name, ok_number);
	for (i = 0; i < lenght; i++)
	{
		assert(results[i].getNumber() == 0);
	}
}

void TestService::testReturnElem()
{
	int i, number_of_products, lenght = 0, ok_product[100], ok_name[100];
	Product products[100], results[100];
	char returnProduct[8] = "Sandals";

	Product product(returnProduct, 0, 5);

	service.returnElem(number_of_products, products, lenght, results, ok_product, ok_name);
	for (i = 0; i < lenght; i++)
	{
		assert(results[i].getNumber() == 5);
	}
}

void TestService::runTestService()
{
	void testAddElem();
	void testUpdateElem();
	void testDelElem();

	void testGetAll();
	void testGetSize();

	void testBuyElem();
	void testReturnElem();
}
