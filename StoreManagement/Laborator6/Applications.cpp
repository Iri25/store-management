#include <iostream>
#include"Product.h"
#include"Repository.h"
#include"RepositoryFile.h"
#include"Service.h"
#include"UserInterface.h"
#include"TestProduct.h"
#include"TestRepository.h"
#include"TestRepositoryFile.h"
#include"TestService.h"

using namespace std;

int main()
{   
    
    //Initial in fisierul ProductsOut.txt sunt urmatoarele date: Dress 150  40, Jacket 150  4, Jeans 60  20
    
    //Initial in fisierul TestProductsOut.txt sunturmatoarele date: Coverall 150  40
  
    //Dupa rulare in fisierul TestProductsOut.txt sunt urmatoarele date: Coverall 150  40, Skirt 60  20, T - shirt 35  10

    //Pentru alta rulare actualizeaza fisierul TestProductsOut.txt cu: Coverall 150  40
    

    TestProduct testProduct;
    testProduct.runTestProduct();

    TestRepository testRepository;
    testRepository.runTestRepository();

    TestRepositoryFile testRepositoryFile;
    testRepositoryFile.runTestRepositoryFile();

    TestService testService;
    testService.runTestService();

    UserInterface userInterface;
    userInterface.initService();
    userInterface.run();
}
