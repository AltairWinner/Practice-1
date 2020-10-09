#pragma once
using namespace std;

const int N = 100;


//Массив
void input_array(int* x, int n);
void out_array(int* x, int n);
void insert_in_position(int* x, int& n, int key, int ind);
void input_random(int* x, int n);
int get_index_of_key(int* x, int n, int key);
int get_count_of_key(int* x, int n, int key);
void delete_by_index(int* x, int& n, int index);
void delete_by_key_slow(int* x, int& n, int key);
void delete_by_key_fast(int* x, int& n, int key);
void order_against_first(int* x, int n);