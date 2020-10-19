#include <iostream>
#include <ctime>

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
//�����������: ������� ������ � �������.
void out_array(int* x, int n)
{
	cout << "����� �������: \n [";
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << "]" << endl;
}

//�����������: ������, � ������� ��������� n<N ���������
//�����������: ��������� � ������� ind �������� ����� key
void insert_in_position(int* x, int& n, const int key, const int ind)
{
	for (int i = n; i > ind; i--)
	{
		x[i] = x[i - 1];
	}
	x[ind] = key;
	n++;
}

//�����������: ������, � ������� ����� ��������� n �����
//�����������: ��������� n ����� � ������� � ������� ���������� ��������� �����
void input_random(int* x, int n)
{
	cout << "���������� ������� ���������� �������" << endl;
	srand(time(0));
	for (int i = 0; i < n; i++)
		x[i] = rand() % 100;
}


//�����������: ����� �������� ����� � �������
//�����������: ���������� ������ �� ��������� 0, n-1 ���� ���� ������
//���� -1, ���� ���� �� ������.
int get_index_of_key(int* x, int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (x[i] == key) return i;
	}
	return -1;
}

//�����������: ������ �� n ���������, 0 <=index<n
//�����������: ���������� ������, ������ ���������
int get_count_of_key(int* x, int n, int key)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i] == key) count++;
	}
	return count;
}

//�����������: ������ �� n ���������, 0 <=index<n
//�����������: ������� ������� � ������� index, �������� ������� ���������� ��������� ���������.
//��������� n.
void delete_by_index_ordered(int* x, int& n, const int index)
{
	for (int i = index; i < n; i++)
	{
		x[i] = x[i + 1];
	}
	n--;
}

//�����������: ������ �� n ���������, 0 <=index<n
//�����������: ������� ������� � ������� index, �� �������� ������� ���������� ��������� ���������.
//��������� n.
void delete_by_index_unordered(int* x, int& n, const int index)
{
	x[index] = x[n - 1];
	n--;
}


//�������� �������� � 2 �������
//�����������: ������ �� n ���������, ���� k, ������� ����� �����
//�����������: ���� �������, ������ key, � ������� ���. ��������� ������� ���������� ��������� ���������
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

//�������� �������� � 1 ������
//�����������: ������ �� n ���������, ���� k, ������� ����� �����
//�����������: ���� �������, ������ key, � ������� ���. ��������� ������� ���������� ��������� ���������.
void delete_by_key_fast(int* x, int& n, const int key)
{
	//����� ����������� ����������
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		x[j] = x[i];
		if (x[i] != key) j++;
	}
	n = j;
}

//�����������: ������ �� n ���������
//�����������: ��������� ������, ���������� ��� �������� ������ ������� ����� ��� � �������� ������� ���������� ���������.
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