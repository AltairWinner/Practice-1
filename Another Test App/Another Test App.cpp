#include <iostream>
using namespace std;

void inparray(int* x, int n);
void outarray(int* x, int n);
void insertInPosition(int*& x, int& n, int key, int ind);
void dell(int*& x, int& n, int key);

int main()
{
    setlocale(LC_ALL, "rus");
    int n, * x;
    cout << "Введите размер массива: ";
    cin >> n;
    x = new int[n];
    inparray(x, n);
    outarray(x, n);
    
    cout << "Добавление в массив" <<endl;
    insertInPosition(x, n, 100, 2);
    outarray(x, n);


    cout << "Удаление из массива" << endl;
    dell(x, n, 100);
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
void insertInPosition(int*& x, int& n, int key, int ind)
{
    //x = (int*)realloc(x, sizeof(int) * (n + 1));

    for (int i = n; i > ind; i--) {
        x[i] = x[i - 1];
    }
    x[ind] = key;
    n++;
}

void dell(int* &x, int& n, int key) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        x[j] = x[i];
        if (x[i] != key) j++;
    }
    n = j;

    //x = (int*)realloc(x, sizeof(int) * (n));
}