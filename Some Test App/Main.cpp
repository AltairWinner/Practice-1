#include <iostream>
#include <ctime>
#include "StaticArray.h"

int main()
{
    setlocale(LC_ALL, "rus");

	//Тесты
	//Объявляем и заполняем массив
    int x[N];
    int n;
	
    cout << "Введите количество элементов для ввода (макс. "<< N <<")" << endl;
    cout << "Либо введите -1 для заполнения массива случайными числами." << endl;
    cin >> n;
	
    if (n == -1)
    {
        cout << "Введите количество элементов в случайном массиве (макс. " << N << ")" << endl;
        cin >> n;
        input_random(x, n);
    }
    else if (n <= 0 || n > N) {  
        cout << "Невозможно создать массив: размер массива неверен" << endl;
        return 0;
    }
    else 
    {
        input_array(x, n);
    }
    out_array(x, n);

    int key;
    cout << "Введите ключ для поиска: ";
    cin >> key;
    int index = get_index_of_key(x, n, key);
    if (index != -1)
        cout << "Найденный индекс по ключу: " << index << endl;
    else
        cout << "Ключ в массиве не найден." << endl;

    //Вставить новое значение в массив в позицию ind
    if (n + 1 == N)
        cout << "В массиве нет свободного места." << endl;
    else
    {
        int ind;
        cout << "Введите индекс места вставки: ";
        cin >> ind;
        if (ind < 0 || ind > n) {
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

    //Удаление элемента 
    cout << "Введите индекс для удаления ключа: ";
    int ind;
    cin >> ind;
    if (ind < 0 || ind > n) {
        cout << "Индекс вне массива" << endl;
    }
    else
    {
        delete_by_index(x, n, ind);
        cout << "Ключ удалён." << endl;
        out_array(x, n);
    }
    
    //По ключу
    cout << "Введите ключ для удаления: ";
    cin >> key;
    delete_by_key(x, n, key);
    cout << "Ключи удалены." << endl;
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
void insert_in_position(int* x, int& n, const int key, const int ind)
{
    for (int i = n; i > ind; i--) {
        x[i] = x[i - 1];
    }
        x[ind] = key;
        n++;
}

void input_random(int* x, int n) {
    cout << "Заполнение массива случайными числами" << endl;
    srand(time(0));
    for (int i = 0; i < n; i++)
        x[i] = rand() % 100;
}


//Предусловие: поиск значения ключа в массиве
//Постусловие: возвращает индекс из диапазона 0, n-1 если ключ найден
//либо -1, если ключ не найден.
int get_index_of_key(const int* x, const int n, const int key) {
    for (int i = 0; i < n; i++) {
        if (x[i] == key) return i;
    }
    return -1;
}

//Предусловие% массив из n элементов, 0 <=index<n
//Постусловие: удаляет элемент в позиции index, сохраняя порядок следования остальных элементов.
//Уменьшает n.
void delete_by_index(int* x, int& n, const int index) {
    for (int i = index; i < n; i++) {
        x[i] = x[i + 1];
    }
    n--;
}

void delete_by_key(int* x, int& n, const int key) {
    /*for (int i = 0; i < n; i++) {
        if (x[i] == key)
        {
            for (int j = i; j < n - 1; j++)
                x[j] = x[j + 1];
            n--;
            i--;
        }
    }*/
//2(n-1)+2(n^2-2n+1)=2n^2-2n; t(n)=f(n)=n^2;

    //Более эффективная реализация
    int j = 0;
    for (int i = 0; i < n; i++) {
        x[j] = x[i];
        if (x[i] != key) j++;
    }
    n = j;
}