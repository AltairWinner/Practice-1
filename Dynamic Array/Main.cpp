#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, *x;
	cout << "Введите размер массива: ";
	cin >> n;
	x = new int[n];
	input_array(x, n);
	out_array(x, n);
	while (true)
	{
		int choice;
		cout << "\nВведите номер пункта меню для продолжения" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "1 - Заполнение массива с клавиатуры" << endl;
		cout << "2 - Вывод массива" << endl;
		cout << "3 - Вставить значение в заданную позицию" << endl;
		cout << "4 - Удалить значение из заданной позиции" << endl;
		cout << "5 - Удалить все значения равные заданному значению, сохраняя порядок следования элементов" << endl;
		cin >> choice;

		if (choice == 0)
			break;

		switch (choice)
		{
		case 1:
			input_array(x, n);
			break;
		case 2:
			out_array(x, n);
			break;
		case 3:
			{
				int key, ind;
				cout << "Введите индекс места вставки: ";
				cin >> ind;
				if (ind < 0 || ind > n)
				{
					cout << "Индекс вне массива" << endl;
				}
				else
				{
					cout << "Введите ключ: ";
					cin >> key;
					insert_in_position(x, n, key, ind);
					cout << "Ключ " << key << " вставлен по индексу " << ind << endl;
					out_array(x, n);
				}
			}
			break;
		case 4:
			{
				cout << "Введите индекс для удаления ключа: ";
				int ind;
				cin >> ind;
				if (ind < 0 || ind > n)
				{
					cout << "Индекс вне массива" << endl;
				}
				else
				{
					delete_by_index(x, n, ind);
					cout << "Ключ удалён." << endl;
				}
			}
			break;
		case 5:
			{
				int key;
				cout << "\nВведите ключ для удаления: ";
				cin >> key;
				delete_by_key(x, n, key);
				cout << "Ключ удалён." << endl;
				break;
			}
		}
	}
}
