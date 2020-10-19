#include <iostream>
#include <ctime>
#include "StaticArray.h"


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
		//cout << "Введите количество элементов в случайном массиве (макс. " << N << ")" << endl;
		//cin >> n;
		input_random(x, n);
		out_array(x, n);
	}
	else
	{
		cout << "Выбран неверный вариант" << endl;
	}
}

void choice_linear_search(int* x, int n)
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

void choice_delete_by_index(int* x, int n)
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
void choice_delete_by_key(int* x, int n)
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

void input_array(int* x, int n)
{
	cout << "Введите " << n << " чисел" << endl;
	for (int i = 0; i < n; i++)
		cin >> x[i];
}

void out_array(int* x, int n)
{
	cout << "Вывод массива: \n [";
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << "]" << endl;
}

//Предусловие: массив, в котором заполнено n<N элементов
//Постусловие: вставляет в позицию ind значение ключа key
void insert_in_position(int* x, int& n, const int key, const int ind)
{
	for (int i = n; i > ind; i--)
	{
		x[i] = x[i - 1];
	}
	x[ind] = key;
	n++;
}

void input_random(int* x, int n)
{
	cout << "Заполнение массива случайными числами" << endl;
	srand(time(0));
	for (int i = 0; i < n; i++)
		x[i] = rand() % 100;
}


//Предусловие: поиск значения ключа в массиве
//Постусловие: возвращает индекс из диапазона 0, n-1 если ключ найден
//либо -1, если ключ не найден.
int get_index_of_key(int* x, int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (x[i] == key) return i;
	}
	return -1;
}

//Предусловие: массив из n элементов, 0 <=index<n
//Постусловие: количество ключей, равных заданному
int get_count_of_key(int* x, int n, int key)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i] == key) count++;
	}
	return count;
}

//Предусловие: массив из n элементов, 0 <=index<n
//Постусловие: удаляет элемент в позиции index, сохраняя порядок следования остальных элементов.
//Уменьшает n.
void delete_by_index_ordered(int* x, int& n, const int index)
{
	for (int i = index; i < n; i++)
	{
		x[i] = x[i + 1];
	}
	n--;
}

void delete_by_index_unordered(int* x, int& n, const int index)
{
	x[index] = x[n-1];
	//x[n-1] = NULL;
	n--;
}


//Алгоритм удаления с 2 циклами
//Предусловие: массив из n элементов, ключ k, который будет удалён
//Постусловие: ищет элемент, равный key, и удаляет его. Сохраняет порядок следования остальных элементов
//2(n-1)+2(n^2-2n+1)=2n^2-2n; t(n)=f(n)=n^2;
void delete_by_key_slow(int* x, int& n, const int key)
{
	for (int i = 0; i < n; i++)
	{
		if (x[i] == key)
		{
			for (int j = i; j < n - 1; j++)
				x[j] = x[j + 1];
			n--;
			i--;
		}
	}
}

//Алгоритм удаления с 1 циклом
//Предусловие: массив из n элементов, ключ k, который будет удалён
//Постусловие: ищет элемент, равный key, и удаляет его. Сохраняет порядок следования остальных элементов.
void delete_by_key_fast(int* x, int& n, const int key)
{
	//Более эффективная реализация
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		x[j] = x[i];
		if (x[i] != key) j++;
	}
	n = j;
}

//Предусловие: массив из n элементов
//Постусловие: сортирует массив, располагая все элементы меньше первого перед ним и сохраняя порядок следования элементов.
void order_against_first(int* x, int n)
{
	int firstElementPosition = 0;
	for (int i = n - 1; i >= firstElementPosition; i--)
	{
		if (x[i] < x[firstElementPosition])
		{
			int movedElement = x[i];
			for (int k = i; k > 0; k--)
				x[k] = x[k - 1];

			x[0] = movedElement;
			firstElementPosition++;
			i++;
		}
	}
	out_array(x, n);
}
