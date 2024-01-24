#pragma once
#include"Repository.h"
#include <fstream>
#include <set>

using namespace std;

template<class T>
class RepositoryFile:public Repository<T>
{
private:
	const char* fis;	
public:
	RepositoryFile();
	RepositoryFile(const char* fileName, const T& item);
	~RepositoryFile();

	void loadFromFile(const char* fileName);
	void saveToFile();

	void addElem(const T& item);
	void updateElem(const T& item1, const T& item2);
	void delElem(const T& item);
};


template<class T>
RepositoryFile<T>::RepositoryFile()
{
	this->fis = "ProductsOut";
}

template<class T>
RepositoryFile<T>::RepositoryFile(const char* fileName, const T& item)
{
	fis = fileName;
	ifstream fin(fileName);
	string line;
	T item;
	while (!fin.eof())
	{
		fin >> item;
	}
	fin.close();
}

template<class T>
inline RepositoryFile<T>::~RepositoryFile()
{

}

template<class T>
void RepositoryFile<T>::loadFromFile(const char* fileName)
{
	this->items.clear();
	fis = fileName;
	ifstream fin(fileName);
	string line;
	char* name = new char[20];
	int price, number;
	while (!fin.eof())
	{
		fin >> name >> price >> number;
		if (name != " ")
		{
			T item(name, price, number);
			this->items.insert(item);
		}
	}
	delete[] name;
	fin.close();
	
	/*T item;
	while (!fin.eof())
	{
		fin >> item;
		this->items.insert(item);
	
	}
	fin.close();*/
}

template<class T>
void RepositoryFile<T>::saveToFile()
{
	ofstream fout(fis);
	set<T> result = this->getAll();
	for (T item : result)
		fout << item << endl;
	fout.close();
}

template<class T>
void RepositoryFile<T>::addElem(const T& item)
{
	this->items.insert(item);
	saveToFile();
}

template<class T>
void RepositoryFile<T>::updateElem(const T& item1, const T& item2)
{
	typename set<T>::iterator it;
	it = find(this->items.begin(), this->items.end(), item1);
	if (it != this->items.end())
	{
		this->items.erase(item1);
		this->items.insert(item2);
	}
	saveToFile();
}

template<class T>
void RepositoryFile<T>::delElem(const T& item)
{
	this->items.erase(item);
	saveToFile();
}