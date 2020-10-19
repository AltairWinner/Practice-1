#include <iostream>
#include <ctime>

using namespace std;

//Предусловие: массив, в который будут вводиться n чисел
//Постусловие: заполняет n чисел в массиве вводом с клавиатуры
void input_array(int* x, int n)
{
	cout << "Введите " << n << " чисел" << endl;
	for (int i = 0; i < n; i++)
		cin >> x[i];
}

//Предусловие: массив x и количество элементов в массиве n.
//Постусловие: выводит массив в консоль.
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

//Предусловие: массив, в который будут вводиться n чисел
//Постусловие: заполняет n чисел в массиве с помощью генератора случайных чисел
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

//Предусловие: массив из n элементов, 0 <=index<n
//Постусловие: удаляет элемент в позиции index, не сохраняя порядок следования остальных элементов.
//Уменьшает n.
void delete_by_index_unordered(int* x, int& n, const int index)
{
	x[index] = x[n - 1];
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