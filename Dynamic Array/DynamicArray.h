#pragma once

#ifndef DynamicArray_H
#define DynamicArray_H
void input_array(int* x, int n);
void out_array(int* x, int n);
void insert_in_position(int*& x, int& n, int key, int ind);
void delete_by_key(int*& x, int& n, int key);
void delete_by_index(int*& x, int& n, int index);
#endif
