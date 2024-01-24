/*
template<class T>
RepositoryFile<T>::RepositoryFile()
{

}

template<class T>
RepositoryFile<T>::RepositoryFile(const char* fileName)
{
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
			Product product(name, price, number);
			items.insert(product);
		}
	}
	delete[] name;

	fin.close();
}

template<class T>
inline RepositoryFile<T>::~RepositoryFile()
{

}

template<class T>
void RepositoryFile<T>::loadFromFile(const char* fileName)
{
	items.clear();
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
			Product product(name, price, number);
			items.insert(product);
		}
	}
	delete[] name;

	fin.close();
}

template<class T>
void RepositoryFile<T>::saveToFile()
{
	items.clear();
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
			Product product(name, price, number);
			items.insert(product);
		}
	}
	delete[] name;

	fin.close();
}

template<class T>
void RepositoryFile<T>::addElem(const T& item)
{
	items.insert(item);
	saveToFile();
}

template<class T>
void RepositoryFile<T>::updateElem(const T& item1, const T& item2)
{
	set<T>::iterator it;
	it = find(items.begin(), items.end(), item1);
	if (it != items.end())
	{
		items.erase(item1);
		items.insert(item2);
	}
	saveToFile();

}

template<class T>
void RepositoryFile<T>::delElem(const T& item)
{
	items.erase(item);
	saveToFile();
}

template<class T>
set<T>& RepositoryFile<T>::getAll()
{
	return items;
	saveToFile();
}

*/