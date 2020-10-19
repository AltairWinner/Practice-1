#include "DynamicArray.h"
#include <iostream>

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
//Постусловие: выводит содержимое массива в консоль.
void out_array(int* x, int n) {
    cout << "Вывод массива: \n [";
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << "]" << endl;
}

//Предусловие: массив, в котором заполнено n<N элементов
//Постусловие: вставляет в позицию ind значение ключа key
void insert_in_position(int*& x, int& n, int key, int ind)
{
    x = static_cast<int*>(realloc(x, sizeof(int) * (n + 1)));

    for (int i = n; i > ind; i--) {
        x[i] = x[i - 1];
    }
    x[ind] = key;
    n++;
}

//Предусловие: массив длиной n и ключ для удаления key
//Постусловие: удаляет из массива все ключи, равные key. Меняет размер массива в памяти. Сохраняет порядок элементов в массиве.
void delete_by_key(int*& x, int& n, const int key) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        x[j] = x[i];
        if (x[i] != key) j++;
    }
    n = j;

    x = static_cast<int*>(realloc(x, sizeof(int) * (n)));
}

//Предусловие: массив длиной n и индекс элемента для удаления index
//Постусловие: удаляет из массива ключ на позиции index. Меняет размер массива в памяти. Сохраняет порядок элементов в массиве.
void delete_by_index(int*& x, int& n, int index)
{
    for (int i = index; i < n; i++)
    {
        x[i] = x[i + 1];
    }
    n--;
	
    x = static_cast<int*>(realloc(x, sizeof(int) * (n)));
}