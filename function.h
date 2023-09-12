#pragma once

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int findIndex(vector<int> &dataSet, int num);
int modifyValue(vector<int> &dataSet, int index, int newNum);
void addInteger(vector<int> &dataSet, int num);
void Remove(vector<int> &dataSet, int index);
