#include <iostream>
#include "DynamicArray.h"


int main()
{
    setlocale(LC_ALL, "rus");
    int n, * x;
    cout << "Введите размер массива: ";
    cin >> n;
    x = new int[n];
    input_array(x, n);
    out_array(x, n);
    
    cout << "Добавление в массив" <<endl;
    insert_in_position(x, n, 100, 2);
    out_array(x, n);


    cout << "Удаление из массива" << endl;
    dell(x, n, 100);
    out_array(x, n);
}

void input_array(int* x, int n)
{
    cout << "Введите " << n << " чисел" << endl;
    for (int i = 0; i < n; i++)
        cin >> x[i];
}

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
    //x = (int*)realloc(x, sizeof(int) * (n + 1));

    for (int i = n; i > ind; i--) {
        x[i] = x[i - 1];
    }
    x[ind] = key;
    n++;
}

//Предусловие: массив длиной n и ключ для удаления key
//Постусловие: удаляет из массива найденный ключ. Меняет размер массива в памяти. Сохраняет порядок элементов в массиве.
void dell(int* &x, int& n, const int key) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        x[j] = x[i];
        if (x[i] != key) j++;
    }
    n = j;

    x = static_cast<int*>(realloc(x, sizeof(int) * (n)));
}