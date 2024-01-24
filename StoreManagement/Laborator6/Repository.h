#pragma once
#include <set>

using namespace std;

template<class T>
class Repository
{
protected:
	set<T> items;
public:
	Repository();
	~Repository();

	void addElem(const T& item);
	void updateElem(const T& item1, const T& item2);
	void delElem(const T& item);

	set<T>& getAll();
	int getSize();

	int findElem(const T& item);
	T elemAtPosition(int i);
};


template<class T>
Repository<T>::Repository()
{

}

template<class T>
Repository<T>::~Repository()
{

}

template<class T>
void Repository<T>::addElem(const T& item)
{
	items.insert(item);
}

template<class T> 
void Repository<T>::updateElem(const T& item1, const T& item2)
{
	typename set<T>::iterator it;
	it = find(items.begin(), items.end(), item1);
	if (it != items.end())
	{
		items.erase(item1);
		items.insert(item2);
	}
}

template<class T> 
void Repository<T>::delElem(const T& item)
{
	items.erase(item);
}

template<class T> 
typename set<T>& Repository<T>::getAll()
{
	return items;
}

template<class T> 
int Repository<T>::getSize()
{
	return items.size();
}

template<class T>
int Repository<T>::findElem(const T& item)
{
	typename set<T>::iterator it = std::find(items.begin(), items.end(), item);
	if (it != items.end())
		return distance(items.begin(), it);
	return -1;
}

template<class T>
T Repository<T>::elemAtPosition(int i)
{
	typename set<T>::iterator it;
	int j = 0;
	for (it = items.begin(); it != items.end(); ++it)
	{
		if (j == i)
			return *it;
		j++;
	}
}

