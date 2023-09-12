#include <iostream>
#include <list>
#include <forward_list>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

#define delimiter "------------------------------------------------------------------------------------\n"
#define tab "\t"

//#define FORWARD_LIST
#define LIST

void main()
{
	setlocale(LC_ALL, "");
#ifdef FORWARD_LIST
	std::forward_list<int> f_list = { 0,1,2,3,5,8,13,21,34 };
	for (int i : f_list) cout << i << tab; cout << endl;
	cout << endl;
	std::forward_list<int>::iterator it;
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	it = f_list.begin();
	if (index == 0) f_list.push_front(value);
	else
	{
		for (int i = 0; i < index - 1; i++, it++);
		f_list.insert_after(it, value);
	}
	for (int i : f_list) cout << i << tab; cout << endl;
	cout << delimiter;
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	it = f_list.begin();
	if (index == 0) f_list.pop_front();
	else
	{
		for (int i = 1; i < index; i++, it++);
		f_list.erase_after(it);
	}
	for (int i : f_list) cout << i << tab; cout << endl;
#endif // FORWARD_LIST

#ifdef LIST
	std::list<int> list = { 0,1,2,3,5,8,13,21,34 };
	for (int i : list) cout << i << tab; cout << endl;
	std::list<int>::iterator it;
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	if (index == 0) list.push_front(value);
	else if (index > list.size() - 1) list.push_back(value);
		else
		{
			if (index < list.size() / 2)
			{
				it = list.begin();
				for (int i = 0; i < index; i++, it++);
				list.insert(it, value);
			}
			else
			{
				it = list.end();
				for (int i = list.size()-1; i > index-1; i--, it--);
				list.insert(it, value);
			}
		}
	for (int i : list) cout << i << tab; cout << endl;
	cout << delimiter;
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	if (index == 0) list.pop_front();
	else if (index > list.size() - 1) list.pop_back();
	else
	{
		if (index < list.size() / 2)
		{
			it = list.begin();
			for (int i = 0; i < index; i++, it++);
			list.erase(it);
		}
		else
		{
			it = list.end();
			for (int i = list.size() - 1; i > index-1; i--, it--);
			list.erase(it);
		}
	}
	for (int i : list) cout << i << tab; cout << endl;
#endif // LIST




}

