#include "DynamicArray.h"
#include <iostream>

using namespace std;

//�����������: ������, � ������� ����� ��������� n �����
//�����������: ��������� n ����� � ������� ������ � ����������
void input_array(int* x, int n)
{
    cout << "������� " << n << " �����" << endl;
    for (int i = 0; i < n; i++)
        cin >> x[i];
}

//�����������: ������ x � ���������� ��������� � ������� n.
//�����������: ������� ���������� ������� � �������.
void out_array(int* x, int n) {
    cout << "����� �������: \n [";
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << "]" << endl;
}

//�����������: ������, � ������� ��������� n<N ���������
//�����������: ��������� � ������� ind �������� ����� key
void insert_in_position(int*& x, int& n, int key, int ind)
{
    x = static_cast<int*>(realloc(x, sizeof(int) * (n + 1)));

    for (int i = n; i > ind; i--) {
        x[i] = x[i - 1];
    }
    x[ind] = key;
    n++;
}

//�����������: ������ ������ n � ���� ��� �������� key
//�����������: ������� �� ������� ��� �����, ������ key. ������ ������ ������� � ������. ��������� ������� ��������� � �������.
void delete_by_key(int*& x, int& n, const int key) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        x[j] = x[i];
        if (x[i] != key) j++;
    }
    n = j;

    x = static_cast<int*>(realloc(x, sizeof(int) * (n)));
}

//�����������: ������ ������ n � ������ �������� ��� �������� index
//�����������: ������� �� ������� ���� �� ������� index. ������ ������ ������� � ������. ��������� ������� ��������� � �������.
void delete_by_index(int*& x, int& n, int index)
{
    for (int i = index; i < n; i++)
    {
        x[i] = x[i + 1];
    }
    n--;
	
    x = static_cast<int*>(realloc(x, sizeof(int) * (n)));
}