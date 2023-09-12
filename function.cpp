#include "function.h"

int findIndex(vector<int> &dataSet, int num) {
  int vSize = dataSet.size();
  for (int i = 0; i < vSize; ++i) {
    if (dataSet[i] == num) {
      return i;
    }
  }
  return -1;
}

int modifyValue(vector<int> &dataSet, int index, int newNum) {
  try {
    int vSize = dataSet.size();
    if (index >= 0 && index < vSize) {
      int oldValue = dataSet[index];
      dataSet[index] = newNum;
      return oldValue;
    } else {
      throw out_of_range("Error: Index is out of range.");
    }
  } catch (const exception &error) {
    cerr << "Error: " << error.what() << endl << endl;
  }
}

void addInteger(vector<int> &dataSet, int num) {
  try {
    dataSet.push_back(num);
  } catch (const exception &error) {
    cerr << "Error: " << error.what() << endl << endl;
  }
}

void Remove(vector<int> &dataSet, int index) {
  int vSize = dataSet.size();
  if (index >= 0 && index < vSize) {
    dataSet.erase(dataSet.begin() + index);
  }
}
