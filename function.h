#pragma once

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// This function finds the index using the number provided by the user
int findIndex(vector<int> &dataSet, int num);
// This function goes to the index provided and modifys the value
int modifyValue(vector<int> &dataSet, int index, int newNum);
// This function add a number to the vector
void addInteger(vector<int> &dataSet, int num);
// This function removes the integer using the index the user provided
void Remove(vector<int> &dataSet, int index);
