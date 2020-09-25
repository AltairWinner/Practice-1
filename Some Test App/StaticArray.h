#pragma once
using namespace std;

const int N = 100;

void input_array(int* x, int n);
void out_array(int* x, int n);
void insert_in_position(int* x, int& n, int key, int ind);
void input_random(int* x, int n);
int get_index_of_key(int* x, int n, int key);
void delete_by_index(int* x, int& n, int index);
void delete_by_key(int* x, int& n, int key);