#include <iostream>
#include "UserInterface.h"

UserInterface::UserInterface()
{

}

UserInterface::UserInterface(Service& service)
{
    this->service = service;
}

UserInterface::~UserInterface()
{

}

void UserInterface::initService()
{
    RepositoryFile<Product> repository;
    repository.loadFromFile("ProductsOut.txt");
    service.setRepository(repository);
}

void UserInterface::readElem()
{
    Product product;
    cin >> product;
	service.addElem(product);
    cout << endl << " The product was added! " << endl;
}

void UserInterface::updateElem()
{
    cout << " Insert the product you want to update! " << endl;
    char* name = new char[20];
    int price = 0, number = 0;
    cout << " Insert the name: ";
    cin >> name;
    Product product1(name, price, number);
    cout << endl;
    Product product2;
    cout << " Insert the new product! " << endl;
    cin >> product2;
    service.updateElem(product1, product2);
    cout << endl << " The product was updated! " << endl;
}

void UserInterface::delElem()
{
    cout << "Insert the product you want to delete! " << endl;
    char* name = new char[20];
    int price = 0, number = 0;
    cout << " Insert the name: ";
    cin >> name;
    Product product(name, price, number);
    service.delElem(product);
    cout << endl << " The product was deleted! " << endl;
}

void UserInterface::buyElem()
{
    int number_of_products, i, price = 0, number, lenght = 0, ok_product[100], ok_name[100], ok_number[100];
    char *name = new char[20];
    Product products[100], results[100];
    cout << " Insert the number of products you want to buy: ";
    cin >> number_of_products;
    for (i = 0; i < number_of_products; i++)
    {
        cout << endl << " Insert the name : ";
        cin >> name;
        cout << " Insert the number: ";
        cin >> number;
        Product product(name, price, number);
        products[i] = product;
    }

    service.buyElem(number_of_products, products, lenght, results, ok_product, ok_name, ok_number);
    for (i = 0; i < lenght; i++)
    {
        Product curentProduct = results[i]; 
        if (curentProduct.getPrice() == 0)
        {
            if (ok_product[i] == 0)
            {
                cout << endl << " The products wasn't bought! " << endl;
            }
            else
            {
                if (ok_name[i] == 0)
                {
                    cout << endl << " The product wasn't bought! " << endl;
                    cout << " The name " << results[i].getName() << " of product did not exist! " << endl;
                }
                else
                {
                    if (ok_number[i] == 0)
                    {
                        cout << endl << " The product wasn't bought! " << endl;
                        cout << " The number " << results[i].getNumber() << " of product did not exist! " << endl;
                    }
                }
            }
        }
        else
        {
            if (ok_product[i] == 1)
            {
                cout << endl << " The product was bought! " << endl;
                cout << results[i].getName() << "  " << results[i].getPrice() << " " << results[i].getNumber() << endl;
            }
        }
    }

}

void UserInterface::returnElem()
{
    int number_of_products, i, price = 0, number, lenght = 0, ok_product[100], ok_name[100];
    char* name = new char[20];
    Product products[100], results[100];
    cout << " Insert the number of products you want to return: ";
    cin >> number_of_products;
    for (i = 0; i < number_of_products; i++)
    {
        cout << endl << " Insert the name : ";
        cin >> name;
        cout << " Insert the number: ";
        cin >> number;
        Product product(name, price, number);
        products[i] = product;
    }

    service.returnElem(number_of_products, products, lenght, results, ok_product, ok_name);
    for (i = 0; i < lenght; i++)
    {
        Product curentProduct = results[i];
        if (curentProduct.getPrice() == 0)
        {
            if (ok_product[i] == 0)
            {
                cout << endl << " The product wasn't return! " << endl;
                cout << " The name " << results[i].getName() << " of product did not exist! " << endl;
            }
        }
        else
        {
            if (ok_product[i] == 1)
            {
                cout << endl << " The product was return! " << endl;
                cout << results[i].getName() << "  " << results[i].getPrice() << " " << results[i].getNumber() << endl;
            }
        }
    }
}

void UserInterface::showAll()
{
    set<Product> product = service.getAll();
    for (Product product : product)
        cout << product << endl;
}

void UserInterface::showMenu()
{
    cout << endl;
    cout << " 0. Exit " << endl;
    cout << " 1. Add " << endl;
    cout << " 2. Show all " << endl;
    cout << " 3. Update " << endl;
    cout << " 4. Delete " << endl;
    cout << " 5. Buy " << endl;
    cout << " 6. Return " << endl;
    cout << endl;
}

void UserInterface::run()
{
    int command;
    while (true)
    {
        showMenu();
        cout << " Insert your option: ";
        cin >> command;
        cout << endl;
        if (command == 0) {
            break;
        }
        if (command == 1)
        {
            readElem();
            cout << endl;
        }
        if (command == 2)
        {
            showAll();
            cout << endl;
        }
        if (command == 3)
        {
            updateElem();
            cout << endl;
        }
        if (command == 4)
        {
            delElem();
            cout << endl;
        }
        if (command == 5)
        {
            buyElem();
            cout << endl;
        }
        if (command == 6)
        {
            returnElem();
            cout << endl;
        }
    }
}