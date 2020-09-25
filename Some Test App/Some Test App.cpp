#include <iostream>
#include <ctime>
using namespace std;

const int N = 100;
void inparray(int* x, int n);
void outarray(int* x, int n);
void insertInPosition(int* x, int& n, int key, int ind);
void inprandom(int* x, int n);
int indexKey(int* x, int n, int key);
void dell(int* x, int& n, int ind);
void delByKey(int* x, int& n, int key);

int main()
{
    setlocale(LC_ALL, "rus");

    int x[N];
    int n;
    cout << "Введите размер массива" << endl;
    cin >> n;
    if (n <= 0 || n > N) {
        cout << "Err" << endl;
        return 0;
    }
    inparray(x, n);
    /*
    outarray(x, n);

    //inprandom(x, n);
    outarray(x, n);

    int key, index;
    cout << "Введите ключ для поиска: ";
    cin >> key;
    index = indexKey(x, n, key);
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
            insertInPosition(x, n, key, ind);
            cout << "Ключ " << key << " вставлен по индексу " << ind << endl;
            outarray(x, n);
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
        dell(x, n, ind);
        cout << "Ключ удалён." << endl;
        outarray(x, n);
    }
    */
    //По ключу
    cout << "Введите ключ для удаления: ";
    int key;
    cin >> key;
    delByKey(x, n, key);
    cout << "Ключи удалены." << endl;
    outarray(x, n);
}

void inparray(int* x, int n)
{
    cout << "Введите " << n << " чисел" << endl;
    for (int i = 0; i < n; i++)
        cin >> x[i];
}

void outarray(int* x, int n) {
    cout << "Вывод массива: \n [";
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << "]" << endl;
}

//Предусловие: массив, в котором заполнено n<N элементов
//Постусловие: вставляет в позицию ind значение ключа key
void insertInPosition(int* x, int& n, int key, int ind)
{
    for (int i = n; i > ind; i--) {
        x[i] = x[i - 1];
    }
        x[ind] = key;
        n++;
}

void inprandom(int* x, int n) {
    cout << "Заполнение массива случайными числами" << endl;
    srand(time(0));
    for (int i = 0; i < n; i++)
        x[i] = rand() % 100;
}


//Предусловие: поиск значения ключа в массиве
//Постусловие: возвращает индекс из диапазона 0, n-1 если ключ найден
//либо -1, если ключ не найден.
int indexKey(int* x, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (x[i] == key) return i;
    }
    return -1;
}

//Предусловие% массив из n элементов, 0 <=ind<n
//Постусловие: удаляет элемент в позиции ind, сохраняя поорядок следования остальных элементов.
//Уменьшает n.
void dell(int* x, int& n, int ind) {
    for (int i = ind; i < n; i++) {
        x[i] = x[i + 1];
    }
    n--;
}

void delByKey(int* x, int& n, int key) {
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