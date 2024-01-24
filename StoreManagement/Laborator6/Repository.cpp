/*
#include "Repository.h"

template <class T> Repository<T>::Repository()
{

}

template <class T> Repository<T>::~Repository()
{

}

template <class T> void Repository<T>::addElem(const T& item)
{
	items.insert(item);
}

template <class T> void Repository<T>::updateElem(const T& item1, const T& item2)
{
	set<T>::iterator it;
	it = find(items.begin(), items.end(), item1);
	if (it != items.end())
	{
		items.erase(item1);
		items.insert(item2);
	}
}

template <class T> void Repository<T>::delElem(const T& item)
{
	items.erase(item);
}

template <class T> set<T>& Repository<T>::getAll()
{
	return items;
}

template <class T> int Repository<T>::getSize()
{
	return items.size();
}
*/