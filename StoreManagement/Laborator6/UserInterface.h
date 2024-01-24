#pragma once
#include "Service.h"
using namespace std;

class UserInterface
{
private:
	Service service;
	
	void readElem();
	void updateElem();
	void delElem();

	void buyElem();
	void returnElem();

	void showAll();

	void showMenu();
public:
	UserInterface();
	UserInterface(Service& service);
	~UserInterface();

	void initService();

	void run();
};