#include <iostream>
#include <ctime>
#include "StaticArray.h"

using namespace std;

void choice_input_array(int* x, int n)
{
	cout << "1. Ввести массив вручную" << endl;
	cout << "2. Ввести массив с помощью генератора случайных чисел" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		input_array(x, n);
		out_array(x, n);
	}
	else if (choice == 2)
	{
		input_random(x, n);
		out_array(x, n);
	}
	else
	{
		cout << "Выбран неверный вариант" << endl;
	}
}

void choice_linear_search(int* x, int &n)
{
	cout << "\nВыберите вариант: " << endl;
	cout << "1. Найти индекс первого вхождения заданного значения в массиве" << endl;
	cout << "2. Найти количество вхождений заданного значения в массиве (поиск всех вхождений)" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		int key;
		cout << "Введите ключ для поиска: ";
		cin >> key;
		int index = get_index_of_key(x, n, key);
		if (index != -1)
			cout << "Найденный индекс по ключу: " << index << endl;
		else
			cout << "Ключ в массиве не найден." << endl;
	}
	else if (choice == 2)
	{
		int key;
		cout << "Введите ключ для поиска: ";
		cin >> key;

		int count = get_count_of_key(x, n, key);
		cout << "Количество вхождений данного значения: " << count << endl;
	}
	else
	{
		cout << "Выбран неверный вариант" << endl;
	}
}

void choice_delete_by_index(int* x, int &n)
{
	cout << "1. Сохраняя порядок следования всех остальных элементов" << endl;
	cout << "2. Не сохраняя порядок следования всех остальных элементов" << endl;

	int choice;
	cin >> choice;
	if (choice == 1) {
		cout << "Введите индекс для удаления ключа: ";
		int ind;
		cin >> ind;
		if (ind < 0 || ind > n)
		{
			cout << "Индекс вне массива" << endl;
		}
		else
		{
			delete_by_index_ordered(x, n, ind);
			cout << "Ключ удалён." << endl;
		}
	}
	else if (choice == 2)
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
			delete_by_index_unordered(x, n, ind);
			cout << "Ключ удалён." << endl;
		}
	}
	else
		cout << "Выбран неверный вариант" << endl;
}
void choice_delete_by_key(int* x, int &n)
{
	int key;
	cout << "\nВведите ключ для удаления: ";
	cin >> key;

	cout << "Выберите используемый алгоритм: " << endl;
	cout << "1. Алгоритм с двумя циклами" << endl;
	cout << "2. Алгоритм с одним циклом" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
		delete_by_key_slow(x, n, key);
	else if (choice == 2)
		delete_by_key_fast(x, n, key);
	else
		cout << "Выбран неверный вариант" << endl;
}

int main()
{
	//Начальная конфигурация
	setlocale(LC_ALL, "rus");
	int x[N];
	int n;

	cout << "Введите количество элементов для ввода (макс. " << N << ")" << endl;
	cin >> n;
	if (n <= 0 || n > N)
	{
		cout << "Невозможно создать массив: размер массива неверен" << endl;
		return 0;
	}
	choice_input_array(x, n);

	while (true)
	{
		int choice;
		cout << "\nВведите номер пункта меню для продолжения" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "1 - Заполнение массива с клавиатуры либо случайно" << endl;
		cout << "2 - Вывод массива" << endl;
		cout << "3 - Вставить значение в заданную позицию" << endl;
		cout << "4 - Линейный поиск" << endl;
		cout << "5 - Удалить значение из заданной позиции" << endl;
		cout << "6 - Удалить все значения равные заданному значению, сохраняя порядок следования элементов" << endl;
		cout <<
			"7 - Упорядочить значения в массиве по правилу: все элементы меньше первого элемента, расположить перед ним, сохраняя порядок следования элементов."
			<< endl;
		cin >> choice;


		//0 - выход из программы
		if (choice == 0)
			break;

		switch (choice)
		{
			//1 - заполнение массива с клавиатуры либо случайно
		case 1:
			choice_input_array(x, n);
			break;
			//2 - вывод массива
		case 2:
			out_array(x, n);
			break;
			//3 - вставить значение в заданную позицию
		case 3:
			if (n + 1 == N)
				cout << "В массиве нет свободного места." << endl;
			else
			{
				int key;
				int ind;
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
			//4 - линейный поиск
		case 4:
			choice_linear_search(x, n);
			break;
			//5 - удалить значение из заданной позиции
		case 5:
			choice_delete_by_index(x, n);
			break;
			//6 - Удалить все значения равные заданному значению, сохраняя порядок следования элементов
		case 6:
			choice_delete_by_key(x, n);
			break;
			//7 - Упорядочить значения в массиве по правилу: все элементы меньше первого элемента, расположить перед ним, сохраняя порядок следования элементов.
		case 7:
			order_against_first(x, n);
			break;

		default:
			cout << "Введен неверный номер действия!";
			break;
		}
	}
}


