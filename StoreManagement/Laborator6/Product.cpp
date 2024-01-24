#include "Product.h"
#include <cstddef>
#include <string.h>
#include <sstream>>
#include <ostream>
#include <iostream>

using namespace std;

Product::Product() 
{
	this->name = NULL;
	this->price = 0;
	this->number = 0;
}

Product::Product(char* name, int price, int number)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->price = price;
	this->number = number;
}

Product::Product(const Product& product) 
{
	this->name = new char[strlen(product.name) + 1];
	strcpy_s(this->name, strlen(product.name) + 1, product.name);
	this->price = product.price;
	this->number = product.number;
}

Product::Product(string line)
{
	std::istringstream iss(line);
	string tok1, tok2, tok3;
	iss >> tok1 >> tok2 >> tok3;
	name = new char[tok1.length() + 1];
	strcpy_s(name, tok1.length() + 1, tok1.c_str());
	price = stoi(tok2);
	number = stoi(tok3);
}

Product::~Product()
{
	if (name)
		delete[]name;
	name = NULL;
	price = -1;
	number = -1;
}

Product& Product::operator=(const Product& product)
{
	if (this == &product)
		return *this;
	if (name)
		delete[] name;
	name = new char[strlen(product.name) + 1];
	strcpy_s(name, strlen(product.name) + 1, product.name);
	price = product.price;
	number = product.number;
	return *this;
}

bool Product:: operator==(const Product& product) const
{
	return (strcmp(name, product.name) == 0);
}

bool Product:: operator!=(const Product& product) const
{
	return (strcmp(name, product.name) != 0);
}

bool Product:: operator<(const Product& product) const
{
	return (strcmp(name, product.name) == -1);
}

bool Product:: operator<=(const Product& product) const
{
	return (strcmp(name, product.name) == 0) || (strcmp(name, product.name) == -1);
}

bool Product:: operator>(const Product& product) const
{
	return (strcmp(name, product.name) == 1);
}

bool Product:: operator>=(const Product& product) const
{
	return (strcmp(name, product.name) == 0) || (strcmp(name, product.name) == 1);
}

char* Product::getName()
{
	return name;
}

int Product::getPrice()
{
	return price;
}

int Product::getNumber() 
{
	return number;
}

void Product::setName(char* name) 
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
}

void Product::setPrice(int price) 
{
	this->price = price;
}

void Product::setNumber(int number) 
{
	this->number = number;
}

std::istream& operator>>(std::istream& is, Product& product)
{
	char* name = new char[20];
	int price, number;
	cout << " Insert the name: ";
	is >> name;
	cout << " Insert the price: ";
	is >> price;
	cout << " Insert the number: ";
	is >> number;
	product.setName(name);
	product.setPrice(price);
	product.setNumber(number);
	delete[] name;
	return is;
}

std::ostream& operator<<(std::ostream& os, Product& product)
{
	os <<product.name << " " << product.price << " " << " " << product.number;
	return os;
}
